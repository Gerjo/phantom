#include "GLUTRenderer.h"
#include <iostream>
#include <GL/freeglut.h>
#include <graphics/Graphics.h>

namespace phantom {

	GLUTRenderer::GLUTRenderer(int width, int height) : Renderer(width, height) {
		std::cout << "Initializing GLUT renderer..." << std::endl;
		int i = 0;
		glutInit(&i, 0);
		glutInitWindowSize(width, height);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glEnable(GL_TEXTURE_2D);
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		//gluOrtho2D(0, width, height, 0); 
		_windowID = glutCreateWindow("Elephantom");
	}

	GLUTRenderer::~GLUTRenderer() {
		glutDestroyWindow(_windowID);
	}

	void GLUTRenderer::drawLoop(std::vector<Composite*> *components) {
		// Get the iterator and start iterating.
		std::vector<Composite*>::iterator compIt = components->begin();
		while(compIt != components->end()) {

			// Get the shapes and start iterating.
			deque<Shape*> *shapes = (*compIt)->getGraphics()->getShapes();
			deque<Shape*>::iterator itShape = shapes->begin();
			while(itShape != shapes->end())	{
				// Load the identity matrix so all coördinates go to the position they belong.
				glLoadIdentity();

				// Begin drawing our shape.
				glBegin(GL_TRIANGLES);
				
				// Change the color of our shape.
				glColor4b((*itShape)->fillColor.r, (*itShape)->fillColor.g, (*itShape)->fillColor.b, (*itShape)->fillColor.a);
				
				// Iterate through all the points located in our shape.
				vector<Eigen::Vector2f>::iterator itVert = (*itShape)->vertices.begin();
				while(itVert != (*itShape)->vertices.end()) {
					glVertex2f((*itShape)->x + (*itVert).x(), (*itShape)->y + (*itVert).y());
                    ++itVert;
				}

				// End of drawing our shape.
				glEnd();

				// Move on to the next shape.
				itShape++;
			}

			// If the component has other components attached to it, draw them aswell.
			if((*compIt)->getComponents()->size() > 0) {
				drawLoop((*compIt)->getComponents());
			}

			// Move on to the next component.
			compIt++;
		}
	}

	void GLUTRenderer::renderLoop(std::vector<GameState*> *states) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		
		std::vector<GameState*>::reverse_iterator iter;
        iter = states->rbegin();
		while(iter != states->rend()) {
			if(iter == states->rend() || !(*iter)->transparent)
				break;

			drawLoop((*iter)->getComponents());
			++iter;
		}
        glLoadIdentity();
        glColor4f(1.0,1.0,1.0,1.0);
        glutSolidTeapot(100);
		glutSwapBuffers();
		glutMainLoopEvent();
	}

}