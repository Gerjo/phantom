#include "Polygon.h"

namespace phantom{
	Polygon::Polygon() {

	}

    void Polygon::addPoint(float x, float y) {
        Vertice v;
        v.x = x;
        v.y = y;
        v.z = 0.0f;
        collection.push_back(v);
    }
}