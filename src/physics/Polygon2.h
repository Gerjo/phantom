#ifndef POLYGON2_H
#define	POLYGON2_H

#include <physics/Vector3.h>
#include <physics/Line2.h>

#include <vector>

using std::vector;

namespace phantom {
    class Polygon2 {
    public:
        Polygon2();
        virtual ~Polygon2();

    private:
        vector<Vector3> _vertices;
    };
}

#endif	/* POLYGON2_H */

