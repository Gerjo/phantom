#include "GLUTRenderer.h"
#include <iostream>
#include <GL/freeglut.h>

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

	void GLUTRenderer::renderLoop() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		
		glutSolidTeapot(0.1f);
		
		glutSwapBuffers();
		glutMainLoopEvent();
	}

}