#include "GLUTGraphics.h"

#include <GL/glut.h>

namespace phantom {
GLUTGraphics::GLUTGraphics(void)
{
	int i = 0;
	glutInit(&i, 0);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutCreateWindow("Elephantom");

}


GLUTGraphics::~GLUTGraphics(void)
{
}


}