#include "GLUTRenderer.h"
#include <iostream>
#include <core/Driver.h>
#include <graphics/Graphics.h>
#include <graphics/VerticeData.h>
#include <graphics/shapes/PNGImage.h>
#include <graphics/shapes/Text.h>
#include <png.h>
#include <graphics/ImageCache.h>

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
        
        if(IsExtensionSupported("GL_ARB_vertex_buffer_object")) {
            glGenBuffersARB = (PFNGLGENBUFFERSARBPROC) wglGetProcAddress("glGenBuffersARB");
            glBindBufferARB = (PFNGLBINDBUFFERARBPROC) wglGetProcAddress("glBindBufferARB");
            glBufferDataARB = (PFNGLBUFFERDATAARBPROC) wglGetProcAddress("glBufferDataARB");
            glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) wglGetProcAddress("glDeleteBuffersARB");
        }
        else{
            cout << "NO VBO SUPPORT FOUND" << endl;
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
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            glTranslatef(shape->x + xOffset, shape->y + yOffset, 0.0f);
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboVertices);
            glVertexPointer(3, GL_FLOAT, 0, (char *) NULL);
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboTexCoords);
            glTexCoordPointer(2, GL_FLOAT, 0, (char *) NULL);
            glDrawArrays(GL_TRIANGLES, 0, shape->vboVerticesCount);

            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            /*glBegin(GL_TRIANGLES);

            // Iterate through all the points located in our shape.
            vector<Vertice>::iterator itVert = shape->vertices.begin();
            vector<TexCoord>::iterator itTex = shape->texCoords.begin();
            if(shape->texCoords.size() > 0) {
            while(itVert != shape->vertices.end()) {
            glTexCoord2f(itTex->u, -itTex->v);
            glVertex2f(shape->x + itVert->x + xOffset, shape->y + itVert->y + yOffset);
            ++itVert;
            ++itTex;
            }
            }
            else {
            while(itVert != shape->vertices.end()) {
            glVertex2f(shape->x + itVert->x + xOffset, shape->y + itVert->y + yOffset);
            ++itVert;
            }
            }

            // End of drawing our shape.
            glEnd();*/
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
    bool GLUTRenderer::IsExtensionSupported( char* szTargetExtension )
    {
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
        // Be sure nothing is left to be deleted.
        if(shape->vboVerticesCount != 0) {
            glDeleteBuffersARB(1, &shape->vboVertices);
            glDeleteBuffersARB(1, &shape->vboTexCoords);
        }

        // Vertices
        glGenBuffersARB(1, &shape->vboVertices);
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboVertices);
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, shape->vertices.size() * 3 * sizeof(float), &shape->vertices, GL_STATIC_DRAW_ARB);

        // Texcoords
        glGenBuffersARB(1, &shape->vboTexCoords);
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboTexCoords);
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, shape->texCoords.size() * 2 * sizeof(float), &shape->texCoords, GL_STATIC_DRAW_ARB);

        shape->vboVerticesCount = shape->vertices.size();

        // While we're at it, we'll do images aswell.
        if(shape->isImage) {
            ImageCacheItem *img = static_cast<PNGImage *>(shape)->getImage();

            glGenTextures(1, &shape->textureID);
            glBindTexture(GL_TEXTURE_2D, shape->textureID);
	        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->width, img->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->imageData);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        }

        // Everything is safe in the videocard... hopefully :)
        shape->vertices.clear();
        shape->texCoords.clear();
    }
}