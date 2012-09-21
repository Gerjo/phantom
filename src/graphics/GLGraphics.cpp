
#include <graphics/GLGraphics.h>
namespace phantom {

	GLGraphics::GLGraphics(){
	}
	GLGraphics::~GLGraphics(){

		glutExit();
	}

	void GLGraphics::setup(PhantomGame *game){
		int i = 0;
		glutInit(&i,0);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(50,50);
		glutInitWindowSize(640,480);
		glutCreateWindow("hello, world");

		//glutMainLoop();
	}

	void GLGraphics::save(){}
	void GLGraphics::restore(){}

	void GLGraphics::fill(){}
	void GLGraphics::stroke(){}
	void GLGraphics::draw(){}

	void GLGraphics::drawLine(Vector2f from, Vector2f to){
		
	}
	void GLGraphics::drawRect(Vector2f xy, Vector2f wh){}
	void GLGraphics::drawFilledRect(Vector2f xy, Vector2f wh){}
	void GLGraphics::drawCircle(Vector2f xy, float radius){}

	void GLGraphics::drawFilledCircle(Vector2f xy, float radius){}

	void GLGraphics::moveTo(float x, float y){}
	void GLGraphics::lineTo(float x, float y){}
}
