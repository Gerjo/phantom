#include "Line.h"
#include <math.h>

namespace phantom{
    Line::Line(float x, float y, float toX, float toY){
        this->x = x;
        this->y = y;
        this->toX = toX;
        this->toY = toY;
        
		drawLine(x, y, toX, toY, 0, 0);

        _bounds = Box3(x, y, toX - x, toY - y);
    }

	void Line::drawLine(float x, float y, float toX, float toY, float offsetX, float offsetY) {
		float x0, x1, x2, x3;
		float y0, y1, y2, y3;
		float length;
		float thickness = 3.0f;

		x0 = 0.0f;
		y0 = 0.0f;

		x1 = toX - x;
		y1 = toY - y;

		length = sqrt(x1 * x1 + y1 * y1);

		x2 = ((y1 * -1) / length) * thickness;
		y2 = (x1 / length) * thickness;

		x3 = x2 + x1;
		y3 = y2 + y1;

		addVertex(x0 + offsetX, y0 + offsetY);
		addVertex(x1 + offsetX, y1 + offsetY);
		addVertex(x2 + offsetX, y2 + offsetY);
		
		addVertex(x2 + offsetX, y2 + offsetY);
		addVertex(x3 + offsetX, y3 + offsetY);
		addVertex(x1 + offsetX, y1 + offsetY);
	}

} /* namespace phantom */