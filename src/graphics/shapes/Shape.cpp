#include "Shape.h"

namespace phantom {

	Shape::Shape()
	{
	}

	Shape::~Shape()
	{
	}

	void Shape::setFillColor(Color color) {
		fillColor = color;
	}

	void Shape::setLineColor(Color color) {
		lineColor = color;
	}
	void Shape::addVertex(float x, float y, float texX, float texY){
		VerticeData data;
		data.x = x;
		data.y = y;
        vertices.push_back(data);
    }
} /* namespace phantom */
