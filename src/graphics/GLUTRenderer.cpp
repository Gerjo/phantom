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
		glEnable(GL_TEXTURE_2D);

		_windowID = glutCreateWindow("Elephantom");
	}

	GLUTRenderer::~GLUTRenderer() {
		glutDestroyWindow(_windowID);
	}

	void GLUTRenderer::setOrtho() {
		glViewport(0,0,width,height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, height, 0, -1000000, 1000000);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void GLUTRenderer::drawLoop(std::vector<Composite*> *components) {
		// Get the iterator and start iterating.
		std::vector<Composite*>::iterator compIt = components->begin();
		while(compIt != components->end()) {

			// Get the shapes and start iterating.
			deque<Shape*> *shapes = (*compIt)->getGraphics()->getShapes();
			deque<Shape*>::iterator itShape = shapes->begin();
			while(itShape != shapes->end())	{
				// Load the identity matrix so all coordinates go to the position they belong.
				glLoadIdentity();

				// Begin drawing our shape.
				glBegin(GL_TRIANGLES);

				// Change the color of our shape.
				glColor4b((*itShape)->fillColor.r, (*itShape)->fillColor.g, (*itShape)->fillColor.b, (*itShape)->fillColor.a);

                // Add the texture.
                if((*itShape)->_imgRows != 0)
                {
                    PNGImage *img = static_cast<PNGImage *>((*itShape));
                    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                    glTexImage2D(GL_TEXTURE_2D, 0, 4, img->getImgWidth(), img->getImgHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, *(*img)._imgRows);
                    cout << *(*img)._imgRows[0];
                    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); 
                    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); 
                    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
                    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
                    glEnable(GL_TEXTURE_2D); 
                    glShadeModel(GL_FLAT); 
                }
                
                // Iterate through all the points located in our shape.
				vector<VerticeData>::iterator itVert = (*itShape)->vertices.begin();
				while(itVert != (*itShape)->vertices.end()) {
                    
					glTexCoord2f(itVert->texX, itVert->texY);
					glVertex2f((*itShape)->x + itVert->x, (*itShape)->y + itVert->y);
                    ++itVert;
				}

				// End of drawing our shape.
				glEnd();

				// Move on to the next shape.
				++itShape;
			}

			// If the component has other components attached to it, draw them as well.
			if((*compIt)->getComponents()->size() > 0) {
				drawLoop((*compIt)->getComponents());
			}

			// Move on to the next component.
			compIt++;
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

            drawLoop((*iter)->getComponents());
            ++iter;
        }


		glutSwapBuffers();
		glutMainLoopEvent();
	}

}