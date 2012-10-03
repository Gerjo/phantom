#include "GLUTRenderer.h"
#include <iostream>
#include <GL/freeglut.h>
#include <graphics/Graphics.h>
#include <graphics/VerticeData.h>
#include <graphics/shapes/PNGImage.h>
#include <png.h>

namespace phantom {

    GLUTRenderer::GLUTRenderer(int width, int height) : Renderer(width, height) {
        std::cout << "Initializing GLUT renderer..." << std::endl;
        int i = 0;
        glutInit(&i, 0);
        glutInitWindowSize(width, height);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

        _windowID = glutCreateWindow("Elephantom");
    }

    GLUTRenderer::~GLUTRenderer() {
        glutDestroyWindow(_windowID);
    }

    void GLUTRenderer::setOrtho() {
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, height, 0, -100, 100);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void GLUTRenderer::drawLoop(std::vector<Composite*> *components, Eigen::Vector3f offset) {

        // Get the iterator and start iterating.
        std::vector<Composite*>::iterator compIt = components->begin();
        while(compIt != components->end()) {
            // Get the shapes and start iterating.
            deque<Shape*> *shapes = & (*compIt)->getGraphics().getFinalizedShapes();

            Eigen::Vector3f offsetRecalculated = offset + (*compIt)->getPosition();

            // Gerjo's double buffer!
            for(int i = 0; i < 2; ++i) {
                deque<Shape*>::iterator itShape = shapes->begin();

                while(itShape != shapes->end())	{
                    drawShape(*itShape, *compIt, offsetRecalculated.x(), offsetRecalculated.y());

                    // Move on to the next shape.
                    ++itShape;
                }

                shapes = & (*compIt)->getGraphics().getBufferedShapes();
            }


            // If the component has other components attached to it, draw them as well.
            if((*compIt)->getComponents()->size() > 0) {
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
        if(shape->imageData != 0) {
            glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_TEXTURE_2D);

            PNGImage *img = static_cast<PNGImage *>(shape);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->getImgWidth(), img->getImgHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, img->imageData);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glNormal3f(0.0, 0.0, 1.0);
        }

        // Add the rotation.
        glRotatef(composite->getGraphics().getRotation(), 0.0f, 0.0f, 1.0f);

        // Begin drawing our shape.
        glBegin(GL_TRIANGLES);

        // Colorize!
        const Color& fillColor = shape->getFillColor();
        glColor4b(fillColor.r, fillColor.g, fillColor.b, fillColor.a);

        // Iterate through all the points located in our shape.
        vector<VerticeData>::iterator itVert = shape->vertices.begin();

        while(itVert != shape->vertices.end()) {
            glTexCoord2f(itVert->texX, itVert->texY);
            glVertex2f(shape->x + itVert->x + xOffset, shape->y + itVert->y + yOffset);
            ++itVert;
        }

        // End of drawing our shape.
        glEnd();

        // Disable the texturing again afterwards.
        if(shape->imageData != 0) {
            glDisable(GL_TEXTURE_2D);
            glPopAttrib();
        }
    }

    void GLUTRenderer::renderLoop(std::deque<GameState*> *states) {
        glClearColor(0.392f, 0.584f, 0.929f, 1.0f );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        setOrtho();

        std::deque<GameState*>::reverse_iterator iter = states->rbegin();
        while(iter != states->rend()) {
            if(!(*iter)->transparent)
                break;

            Eigen::Vector3f initialOffset(0, 0, 0);

            drawLoop((*iter)->getComponents(), initialOffset);
            ++iter;
        }

        glFlush();
        glutSwapBuffers();
        glutMainLoopEvent();
    }

}