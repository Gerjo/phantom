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

		glClearColor(0.5f, 0.5f, 0.5f, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
	
		glutCreateWindow("Elephantom");
	}

	GLUTRenderer::~GLUTRenderer() {
	}

	void GLUTRenderer::renderLoop() {
		glutMainLoopEvent();
	}

}