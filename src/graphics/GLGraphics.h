#ifndef GLGRAPHICS_H
#define GLGRAPHICS_H

#include <graphics\Graphics.h>
#include <GL\freeglut.h>

namespace phantom{

	class GLGraphics : Graphics{
		GLGraphics();
		virtual ~GLGraphics() {};

		void onAdd(Composite *parent);

		virtual void setup(PhantomGame *game);

		virtual void save();
		virtual void restore();

		virtual void fill();
		virtual void stroke();
		virtual void draw();

		virtual void drawLine(Vector2f from, Vector2f to);
		virtual void drawRect(Vector2f xy, Vector2f wh);
		virtual void drawFilledRect(Vector2f xy, Vector2f wh);
		virtual void drawCircle(Vector2f xy, float radius);

		virtual void drawFilledCircle(Vector2f xy, float radius);

		virtual void moveTo(float x, float y);
		virtual void lineTo(float x, float y);

	};
}

#endif