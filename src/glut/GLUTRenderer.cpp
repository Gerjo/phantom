#include "GLUTRenderer.h"
#include <iostream>
#include <core/Driver.h>
#include <graphics/Graphics.h>
#include <graphics/VerticeData.h>
#include <graphics/shapes/PNGImage.h>
#include <graphics/shapes/Text.h>
#include <png.h>
#include <graphics/ImageCache.h>

#ifndef _WINDOWS
#   include <GL/glx.h>
#endif

// Makes my life a bit easyer
PFNGLGENBUFFERSARBPROC glGenBuffersARB = NULL;
PFNGLBINDBUFFERARBPROC glBindBufferARB = NULL;
PFNGLBUFFERDATAARBPROC glBufferDataARB = NULL;
PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB = NULL;

namespace phantom {

    GLUTRenderer::GLUTRenderer(PhantomGame *game) : Renderer(game) {
        std::cout << "Initializing GLUT renderer..." << std::endl;
        int i = 0;
        glutInit(&i, 0);
        glutInitWindowSize(static_cast<int>(game->getViewPort().x), static_cast<int>(game->getViewPort().y));
        glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA);
        _windowID = glutCreateWindow("Elephantom");

        _vboSupport = IsExtensionSupported("GL_ARB_vertex_buffer_object");
        if(_vboSupport) {

            // Yes, i'm lazy.
#ifdef _WINDOWS
#   define GetProcAddress(X) wglGetProcAddress(X)
#else
#   ifdef GLX_VERSION_1_4
#       define GetProcAddress(X) glXGetProcAddress(reinterpret_cast<const GLubyte*>(X))
#   else
#       define GetProcAddress(X) glXGetProcAddressARB(reinterpret_cast<const GLubyte*>(X))
#   endif
#endif

            glGenBuffersARB = (PFNGLGENBUFFERSARBPROC) GetProcAddress("glGenBuffersARB");
            glBindBufferARB = (PFNGLBINDBUFFERARBPROC) GetProcAddress("glBindBufferARB");
            glBufferDataARB = (PFNGLBUFFERDATAARBPROC) GetProcAddress("glBufferDataARB");
            glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) GetProcAddress("glDeleteBuffersARB");
        }
        else{
            cout << "There is no VBO support." << endl;
        }
    }

    GLUTRenderer::~GLUTRenderer() {
        glutDestroyWindow(_windowID);
    }

    void GLUTRenderer::drawLoop(std::vector<Composite*>& components, Vector3& offset) {

        if(_game->getDriver()->getActiveCamera() == 0)
            return;

        bool isDrawable = false;
        Vector3 cameraPosition = _game->getDriver()->getActiveCamera()->getPosition();
        Box3 cameraBox(cameraPosition.x, cameraPosition.y, _game->getWorldSize().x, _game->getWorldSize().y);

        // Get the iterator and start iterating.
        std::vector<Composite*>::iterator compIt = components.begin();
        while(compIt != components.end()) {
            Vector3 offsetRecalculated = offset + (*compIt)->getPosition();
            // Get the shapes and start iterating.
            deque<Shape*> *shapes = & (*compIt)->getGraphics().getFinalizedShapes();

            // Gerjo's double buffer!
            for(int i = 0; i < 2; ++i) {
                deque<Shape*>::iterator itShape = shapes->begin();

                while(itShape != shapes->end())	{
                    Box3 shapeBox = (*itShape)->getBounds();
                    shapeBox.origin.x += offsetRecalculated.x;
                    shapeBox.origin.y += offsetRecalculated.y;

                    if(shapeBox.origin.x + shapeBox.size.x >= cameraBox.origin.x && shapeBox.origin.x + shapeBox.size.x <= cameraBox.origin.x + cameraBox.size.x &&
                        shapeBox.origin.y + shapeBox.size.y >= cameraBox.origin.y && shapeBox.origin.y + shapeBox.size.y <= cameraBox.origin.y + cameraBox.size.y)
                    {
                        isDrawable = true;
                    }
                    // Draw the shape.
                    if(isDrawable)
                        drawShape(*itShape, *compIt, offsetRecalculated.x, offsetRecalculated.y);

                    // Move on to the next shape.
                    ++itShape;
                }

                shapes = & (*compIt)->getGraphics().getBufferedShapes();

            }

            // If the component has other components attached to it, draw them as well.
            if((*compIt)->getComponents().size() > 0) {
                drawLoop((*compIt)->getComponents(), offsetRecalculated);
            }

            // Move on to the next component.
            compIt++;
        }
    }

    void GLUTRenderer::drawShape(Shape *shape, Composite *composite, float xOffset, float yOffset) {
        // Load the identity matrix so all coordinates go to the position they belong.
        glLoadIdentity();

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glDisable(GL_COLOR_MATERIAL);

        // Add the texture.
        if(shape->isImage) {
            glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, shape->textureID);

            glNormal3f(0.0f, 0.0f, 1.0f);
        }

        // Add the rotation.
        glRotatef(composite->getGraphics().getRotation(), 0.0f, 0.0f, 1.0f);

        // Begin drawing our shape.
        if(!shape->isText) {
            // Colorize!
            const Color& fillColor = shape->getFillColor();
            glColor4b(fillColor.r, fillColor.g, fillColor.b, fillColor.a);

            // Enable Pointers
            glEnableClientState(GL_VERTEX_ARRAY);

            if(shape->isImage)
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            glTranslatef(shape->x + xOffset, shape->y + yOffset, 0.0f);
            if(_vboSupport) {
                glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboVertices);
                glVertexPointer(3, GL_FLOAT, 0, (char *) NULL);

                if(shape->isImage) {
                    glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboTexCoords);
                    glTexCoordPointer(2, GL_FLOAT, 0, (char *) NULL);
                }
            }
            else {
                glVertexPointer(3, GL_FLOAT, 0, shape->verticesArray);
                if(shape->isImage) {
                    glTexCoordPointer(2, GL_FLOAT, 0, shape->texCoordsArray);
                }
            }

            glDrawArrays(GL_TRIANGLES, 0, shape->verticesCount);

            glDisableClientState(GL_VERTEX_ARRAY);
            if(shape->isImage)
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        }
        else
        {
            // Colorize!
            const Color& fillColor = shape->getFillColor();
            glColor4b(fillColor.r, fillColor.g, fillColor.b, fillColor.a);

            Text *txt = static_cast<Text *>(shape);
            glRasterPos2f(shape->x, shape->y);
            glutBitmapString(txt->font, txt->text);
        }

        // Disable the texturing again afterwards.
        if(shape->isImage) {
            glDisable(GL_TEXTURE_2D);
            glPopAttrib();
        }
    }

    void GLUTRenderer::renderLoop(std::deque<GameState*> *states) {
        glClearColor(0.42f, 0.145f, 0.016f, 1.0f );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        std::deque<GameState*>::reverse_iterator iter = states->rbegin();
        while(iter != states->rend()) {
            if(!(*iter)->transparent)
                break;

            Vector3 initialOffset(0, 0, 0);

            drawLoop((*iter)->getComponents(), initialOffset);
            ++iter;
        }

        glutMainLoopEvent();
        glFlush();
    }

    // Based Off Of Code Supplied At OpenGL.org
    bool GLUTRenderer::IsExtensionSupported(std::string szTargetExtensionString )
    {
        const char* szTargetExtension = szTargetExtensionString.c_str();
        const unsigned char *pszExtensions = NULL;
        const unsigned char *pszStart;
        unsigned char *pszWhere, *pszTerminator;

        // Extension names should not have spaces
        pszWhere = (unsigned char *) strchr( szTargetExtension, ' ' );
        if( pszWhere || *szTargetExtension == '\0' )
            return false;

        // Get Extensions String
        pszExtensions = glGetString( GL_EXTENSIONS );

        // Search The Extensions String For An Exact Copy
        pszStart = pszExtensions;
        for(;;)
        {
            pszWhere = (unsigned char *) strstr( (const char *) pszStart, szTargetExtension );
            if( !pszWhere )
                break;
            pszTerminator = pszWhere + strlen( szTargetExtension );
            if( pszWhere == pszStart || *( pszWhere - 1 ) == ' ' )
                if( *pszTerminator == ' ' || *pszTerminator == '\0' )
                    return true;
            pszStart = pszTerminator;
        }
        return false;
    }

    void GLUTRenderer::buildVBO(Shape *shape) {
        if(_vboSupport) {
            // Be sure nothing is left to be deleted.
            if(shape->verticesCount != 0) {
                glDeleteBuffersARB(1, &shape->vboVertices);
                glDeleteBuffersARB(1, &shape->vboTexCoords);
            }
            shape->verticesCount = shape->vertices.size();

            // Creating REAL arrays -.-
            Vertice *verticesArray = new Vertice[shape->verticesCount];
            TexCoord *texCoordArray;
            if(shape->isImage)
                texCoordArray = new TexCoord[shape->verticesCount];

            for(unsigned int i = 0; i < shape->verticesCount; ++i) {
                verticesArray[i] = shape->vertices[i];
                if(shape->isImage)
                    texCoordArray[i] = shape->texCoords[i];
            }

            // Vertices
            glGenBuffersARB(1, &shape->vboVertices);
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboVertices);
            glBufferDataARB(GL_ARRAY_BUFFER_ARB, shape->verticesCount * 3 * sizeof(float), verticesArray, GL_STATIC_DRAW_ARB);

            // Texcoords
            if(shape->isImage) {
                glGenBuffersARB(1, &shape->vboTexCoords);
                glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboTexCoords);
                glBufferDataARB(GL_ARRAY_BUFFER_ARB, shape->verticesCount * 2 * sizeof(float), texCoordArray, GL_STATIC_DRAW_ARB);
            }

            // Everything is safe in the videocard... hopefully :)
            shape->vertices.clear();
            shape->texCoords.clear();

            delete [] verticesArray;
            if(shape->isImage)
                delete [] texCoordArray;
        } else {
            if(shape->verticesArray != 0)
                delete [] shape->verticesArray;
            if(shape->texCoordsArray != 0)
                delete [] shape->texCoordsArray;

            shape->verticesCount = shape->vertices.size();

            // Creating REAL arrays -.-
            shape->verticesArray = new Vertice[shape->vertices.size()];
            
            if(shape->isImage)
                shape->texCoordsArray = new TexCoord[shape->vertices.size()];

            for(unsigned int i = 0; i < shape->vertices.size(); ++i) {
                shape->verticesArray[i] = shape->vertices[i];
                if(shape->isImage)
                    shape->texCoordsArray[i] = shape->texCoords[i];
            }
        }

        // While we're at it, we'll do images aswell.
        if(shape->isImage) {
            ImageCacheItem *img = static_cast<PNGImage *>(shape)->getImage();

            glGenTextures(1, &shape->textureID);
            glBindTexture(GL_TEXTURE_2D, shape->textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->width, img->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->imageData);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        }
    }
}