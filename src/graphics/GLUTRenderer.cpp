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

		glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
		
		_windowID = glutCreateWindow("Elephantom");
	}

	GLUTRenderer::~GLUTRenderer() {
		glutDestroyWindow(_windowID);
	}

	void GLUTRenderer::drawLoop(std::vector<Composite*> *components) {
	}

	void GLUTRenderer::renderLoop(std::vector<GameState*> *states) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		
		std::vector<GameState*>::reverse_iterator iter;
		iter = states->rend();
		while(iter != states->rbegin()) {
			if(iter == states->rbegin() || (*iter)->transparent)
				break;

			std::vector<Composite*> *components = (*iter)->getComponents();
			std::vector<Composite*>::iterator compIt;
			while(compIt != components->end()) {
				deque<Shape*> *shapes = (*compIt)->getGraphics()->getShapes();
			}

			--iter;
		}
		
		glutSwapBuffers();
		glutMainLoopEvent();
	}

}