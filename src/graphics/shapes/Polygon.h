#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

namespace phantom{
	class LIBEXPORT Polygon: public Shape {
	public:
		Polygon();

        void addPoint(float x, float y);
        vector<Vertice> collection;
	};
}/*namespace phantom*/

#endif /* POLYGON_H */