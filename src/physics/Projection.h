#ifndef PROJECTION_H
#define	PROJECTION_H

#include <CompileConfig.h>
#include <physics/Line2.h>
#include <physics/Vector3.h>
#include <physics/Box3.h>
#include <deque>
#include <limits>

using namespace phantom;

class LIBEXPORT Projection {
public:
    typedef std::deque<Vector3> Group;

    static Line2 project(const Vector3 axis, const Group& vertices) {
        const float inf = std::numeric_limits<float>::infinity();
        Vector3 max(-inf, -inf, 0.0f);
        Vector3 min(inf, inf, 0.0f);

        // Project each vertex on the axis, and determine the upper and lower bound.
        for(const Vector3& vertex : vertices) {
            Vector3 projection = vertex.projectOnto(axis);

            if(projection.x > max.x) {
                max = projection;
            }

            if(projection.x < min.x) {
                min = projection;
            }
        }
        
        return Line2(min, max);
    }
};


#endif	/* PROJECTION_H */

