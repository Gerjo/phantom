#include "GLRenderer.h"
#include <iostream>
#include <core/Driver.h>
#include <graphics/Graphics.h>
#include <graphics/VerticeData.h>
#include <graphics/shapes/Image.h>
#include <graphics/shapes/Text.h>
#include <graphics/particles/Particles.h>
#include <png.h>
#include <graphics/ImageCache.h>

namespace phantom {

    PFNGLGENBUFFERSARBPROC glGenBuffersARB = NULL;
    PFNGLBINDBUFFERARBPROC glBindBufferARB = NULL;
    PFNGLBUFFERDATAARBPROC glBufferDataARB = NULL;
    PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB = NULL;

    GLRenderer::GLRenderer(PhantomGame *game) : Renderer(game) {
        std::cout << "Initializing GL renderer..." << std::endl;
        Vector3 screenSize = game->getScreenSize();

        int i = 0;
        glutInit(&i, 0);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE);
        glutInitWindowSize(static_cast<int>(screenSize.x), static_cast<int>(screenSize.y));

        if(!game->fullscreen) {
            _windowID = glutCreateWindow("CpPhantom");
        }
        else if(game->fullscreen) {
            std::stringstream stream;
            std::string gamemodeStr;

            stream << screenSize.x << "x" << screenSize.y << ":32@60";

            gamemodeStr = stream.str();

            glutGameModeString(gamemodeStr.c_str());

            if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
                glutEnterGameMode();
            }
        }

        if(!game->mousecursor) {
            glutSetCursor(GLUT_CURSOR_NONE);
        }

        _vboSupport = IsExtensionSupported("GL_ARB_vertex_buffer_object");
        if(_vboSupport) {

#ifdef _WINDOWS
#   define GetProcAddress(X) wglGetProcAddress(X)
#else
#   ifdef GLX_VERSION_1_4
#       define GetProcAddress(X) glXGetProcAddress(reinterpret_cast<const GLubyte*>(X))
#   else
#       define GetProcAddress(X) glXGetProcAddressARB(reinterpret_cast<const GLubyte*>(X))
#   endif
#endif

            glGenBuffersARB    = (PFNGLGENBUFFERSARBPROC)    GetProcAddress("glGenBuffersARB");
            glBindBufferARB    = (PFNGLBINDBUFFERARBPROC)    GetProcAddress("glBindBufferARB");
            glBufferDataARB    = (PFNGLBUFFERDATAARBPROC)    GetProcAddress("glBufferDataARB");
            glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) GetProcAddress("glDeleteBuffersARB");
        }
        else{
            cout << "There is no VBO support." << endl;
        }
    }

    GLRenderer::~GLRenderer() {
        glutDestroyWindow(_windowID);
    }

    void GLRenderer::drawText(Text *txt, Composite *composite, float xOffset, float yOffset) {
        glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, txt->ftfont->texture->textureID);

        const Color& fillColor = txt->getFillColor();
        glColor4b(fillColor.r, fillColor.g, fillColor.b, fillColor.a);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glTranslatef(txt->x + xOffset, txt->y + yOffset, 0.0f);
        glRotatef(composite->getGraphics().getRotation(), 0.0f, 0.0f, 1.0f);
        if(_vboSupport) {
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, txt->vboVertices);
            glVertexPointer(3, GL_FLOAT, 0, (char *) NULL);

            glBindBufferARB(GL_ARRAY_BUFFER_ARB, txt->vboTexCoords);
            glTexCoordPointer(2, GL_FLOAT, 0, (char *) NULL);

        }
        else {
            glVertexPointer(3, GL_FLOAT, 0, txt->verticesArray);
            glTexCoordPointer(2, GL_FLOAT, 0, txt->texCoordsArray);
        }

        glDrawArrays(GL_QUADS, 0, txt->verticesCount);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisable(GL_TEXTURE_2D);
        glPopAttrib();
    }

    void GLRenderer::drawImage(Image *img, Composite *composite, float xOffset, float yOffset) {
        glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, img->getImage()->textureID);

        const Color& fillColor = img->getFillColor();
        glColor4b(fillColor.r, fillColor.g, fillColor.b, fillColor.a);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glTranslatef(img->x + xOffset, img->y + yOffset, 0.0f);
        glRotatef(composite->getGraphics().getRotation(), 0.0f, 0.0f, 1.0f);
        if(_vboSupport) {
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, img->vboVertices);
            glVertexPointer(3, GL_FLOAT, 0, (char *) NULL);

            glBindBufferARB(GL_ARRAY_BUFFER_ARB, img->vboTexCoords);
            glTexCoordPointer(2, GL_FLOAT, 0, (char *) NULL);

        }
        else {
            glVertexPointer(3, GL_FLOAT, 0, img->verticesArray);
            glTexCoordPointer(2, GL_FLOAT, 0, img->texCoordsArray);
        }

        glDrawArrays(GL_TRIANGLES, 0, img->verticesCount);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        glDisable(GL_TEXTURE_2D);
        glPopAttrib();
    }

    void GLRenderer::drawPrime(Shape *shape, Composite *composite, float xOffset, float yOffset) {
        const Color& fillColor = shape->getFillColor();
        glColor4b(fillColor.r, fillColor.g, fillColor.b, fillColor.a);

        glEnableClientState(GL_VERTEX_ARRAY);

        glTranslatef(shape->x + xOffset, shape->y + yOffset, 0.0f);
        glRotatef(composite->getGraphics().getRotation(), 0, 0, 1.0f);
        if(_vboSupport) {
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, shape->vboVertices);
            glVertexPointer(3, GL_FLOAT, 0, (char *) NULL);
        }
        else {
            glVertexPointer(3, GL_FLOAT, 0, shape->verticesArray);
        }

        glDrawArrays(GL_TRIANGLES, 0, shape->verticesCount);

        glDisableClientState(GL_VERTEX_ARRAY);
    }

    void GLRenderer::drawParticles(Particles *particles, float xOffset, float yOffset) {
        const vector<Particle*>* p = particles->getParticles();
        glLoadIdentity();
        glTranslatef(particles->getPosition().x + xOffset, particles->getPosition().y + yOffset, particles->getPosition().z);
        for(auto *particle : *p) {
            glPushMatrix();
            glColor4b(particle->color.r, particle->color.g, particle->color.b, particle->color.a);
            glTranslatef(particle->position.x, particle->position.y, particle->position.z);
            glScalef(particle->scale.x, particle->scale.y, particle->scale.z);

            if(particles->texture != nullptr) {
                glBlendFunc(GL_DST_COLOR, GL_ZERO);
                glBindTexture(GL_TEXTURE_2D, particles->texture->textureID);
            }

            // Should be added to VBO's
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex3f(-1, -1, 0);
            glTexCoord2d(1, 0);
            glVertex3f(1, -1, 0);
            glTexCoord2d(1, 1);
            glVertex3f(1, 1, 0);
            glTexCoord2d(0, 1);
            glVertex3f(-1, 1, 0);
            glEnd();

            glPopMatrix();
        }
    }

    void GLRenderer::drawShapes(Composite *composite, const Box3 &cameraBox, float xOffset, float yOffset) {
        vector<Shape*> *shapes = &composite->getGraphics().getFinalizedShapes();

        for(int i = 0; i < 2; ++i) {
            vector<Shape*>::iterator itShape = shapes->begin();

            while(itShape != shapes->end())	{
                Box3 shapeBox = (*itShape)->getBounds();
                shapeBox.origin.x += xOffset;
                shapeBox.origin.y += yOffset;

                if(shapeBox.intersect(cameraBox)) {
                    glLoadIdentity();

                    if((*itShape)->isImage) {
                        drawImage(static_cast<Image *>(*itShape), composite, xOffset, yOffset);
                    }
                    else if((*itShape)->isText) {
                        drawText(static_cast<Text *>(*itShape), composite, xOffset, yOffset);
                    }
                    else {
                        drawPrime((*itShape), composite, xOffset, yOffset);
                    }
                }
                ++itShape;
            }
            shapes = &composite->getGraphics().getBufferedShapes();
        }
    }


    void GLRenderer::drawLoop(std::vector<Composite*> &components, Vector3 &offset) {
        if(_game->getDriver()->getActiveCameras()->size() == 0)
            return;

        for(Camera *cam : *_game->getDriver()->getActiveCameras()) {
            cam->setParams();
            Vector3 cameraPosition = cam->getPosition();
            Box3 cameraBox(cam->getPosition(), _game->getViewPort());

            std::vector<Composite*>::iterator compIt = components.begin();
            while(compIt != components.end()) {
                Vector3 offsetRecalculated = offset + (*compIt)->getPosition();

                Particles *particles = nullptr;
                if((particles = dynamic_cast<Particles*>(*compIt)) != nullptr) {
                    drawParticles(particles, offsetRecalculated.x, offsetRecalculated.y);
                }
                else {
                    drawShapes((*compIt), cameraBox, offsetRecalculated.x, offsetRecalculated.y);
                }

                if((*compIt)->getComponents().size() > 0) {
                    drawLoop((*compIt)->getComponents(), offsetRecalculated);
                }

                compIt++;
            }
        }
    }

    void GLRenderer::renderLoop(std::deque<GameState*> *states) {
        glClearColor(0.42f, 0.145f, 0.016f, 1.0f );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);

        Vector3 initialOffset(0, 0, 0);

        for(GameState* gamestate : *states) {
            if(gamestate->doRender) {
                drawLoop(gamestate->getComponents(), initialOffset);
                for(Camera *camera : *_game->getDriver()->getActiveCameras()) {
                    camera->setParams();
                    Box3 cameraBox(camera->getPosition(), _game->getViewPort());
                    drawShapes(gamestate, cameraBox, initialOffset.x, initialOffset.y);
                }
            }
        }

        drawLoop(_game->getComponents(), initialOffset);

        glutMainLoopEvent();
        glutSwapBuffers();
        glFlush();
    }

    void GLRenderer::createVBO(GLuint *buffer, GLuint size, GLvoid *data) {
        glGenBuffersARB(1, buffer);
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, *buffer);
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, size, data, GL_STATIC_DRAW_ARB);
    }

    void GLRenderer::destroyVBO(GLuint *buffer) {
        glDeleteBuffersARB(1, buffer);
    }

    void GLRenderer::buildShape(Shape *shape) {
        // Be sure nothing is left to be deleted.
        destroyShape(shape);

        if(_vboSupport) {
            shape->verticesCount = shape->vertices.size();

            Vertice *verticesArray = new Vertice[shape->verticesCount];
            TexCoord *texCoordArray;
            if(shape->isImage || shape->isText)
                texCoordArray = new TexCoord[shape->verticesCount];

            for(unsigned int i = 0; i < shape->verticesCount; ++i) {
                verticesArray[i] = shape->vertices[i];
                if(shape->isImage || shape->isText)
                    texCoordArray[i] = shape->texCoords[i];
            }

            createVBO(&shape->vboVertices, shape->verticesCount * 3 * sizeof(float), verticesArray);

            if(shape->isImage || shape->isText) {
                createVBO(&shape->vboTexCoords, shape->verticesCount * 2 * sizeof(float), texCoordArray);
            }

            shape->vertices.clear();
            shape->texCoords.clear();

            delete [] verticesArray;
            if(shape->isImage || shape->isText)
                delete [] texCoordArray;
        } else if (!_vboSupport) {
            shape->verticesCount = shape->vertices.size();

            shape->verticesArray = new Vertice[shape->vertices.size()];
            if(shape->isImage || shape->isText)
                shape->texCoordsArray = new TexCoord[shape->vertices.size()];

            for(unsigned int i = 0; i < shape->vertices.size(); ++i) {
                shape->verticesArray[i] = shape->vertices[i];
                if(shape->isImage || shape->isText)
                    shape->texCoordsArray[i] = shape->texCoords[i];
            }
        }
    }

    void GLRenderer::destroyShape(Shape *shape) {
        if(_vboSupport) {
            destroyVBO(&shape->vboVertices);
            if(shape->isImage || shape->isText)
                destroyVBO(&shape->vboTexCoords);

            shape->verticesCount = 0;
        }
        else {
            delete [] shape->verticesArray;
            delete [] shape->texCoordsArray;

            shape->verticesArray = 0;
            shape->texCoordsArray = 0;
        }
    }

    void GLRenderer::addTexture(ImageCacheItem *item, bool isText) {
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &item->textureID);
        glBindTexture(GL_TEXTURE_2D, item->textureID);

        if(!isText)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, item->width, item->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, item->imageData);
        else
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, item->width, item->height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, item->imageData);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

        glDisable(GL_TEXTURE_2D);
    }

    void GLRenderer::removeTexture(ImageCacheItem *item) {
        if(item->textureID != 0) {
            glDeleteTextures(1, &item->textureID);
            item->textureID = 0;
        }
    }

    // Based Off Of Code Supplied At OpenGL.org
    bool GLRenderer::IsExtensionSupported(std::string szTargetExtensionString )
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
}
