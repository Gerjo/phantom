#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

namespace phantom{
	class LIBEXPORT Polygon: public Shape {
	public:
		Polygon();

        /**
        * Adds a point in the polygon to draw a line next to.
        *
        * @param x Location of the next vertex ( X-coordinate ).
        * @param y Location of the next vertex ( Y-coordinate ).
        */
        void addPoint(float x, float y);
        vector<Vertice> collection;
	};
}/*namespace phantom*/

#endif /* POLYGON_H */