#include "Line.h"
#include <math.h>

namespace phantom{
    Line::Line(float x, float y, float toX, float toY){
        this->x = x;
        this->y = y;
        this->toX = toX;
        this->toY = toY;
        
		float x0, x1, x2, x3;
		float y0, y1, y2, y3;
		float length;
		float thickness = 5.0f;

		x0 = 0.0f;
		y0 = 0.0f;

		x1 = toX - x;
		y1 = toY - y;

		length = sqrt(x1 * x1 + y1 * y1);

		x2 = ((y1 * -1) / length) * thickness;
		y2 = (x1 / length) * thickness;

		x3 = x2 + x1;
		y3 = y2 + y1;

		addVertex(x0, y0);
		addVertex(x1, y1);
		addVertex(x2, y2);
		
		addVertex(x2, y2);
		addVertex(x3, y3);
		addVertex(x1, y1);

    }
} /* namespace phantom */