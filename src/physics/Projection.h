#ifndef PROJECTION_H
#define	PROJECTION_H

#include <CompileConfig.h>
#include <physics/Line2.h>
#include <physics/Vector3.h>
#include <physics/Box3.h>
#include <deque>
#include <limits>
#include <iostream>

using std::cout;
using std::endl;

using namespace phantom;

class LIBEXPORT Projection {
public:
    typedef std::deque<Vector3> Group;

    static Line2 project(const Vector3 axis, const Group& vertices) {
        const float inf = std::numeric_limits<float>::infinity();
        Vector3 maximum(-inf, -inf, 0.0f);
        Vector3 minimum(inf, inf, 0.0f);

        // Project each vertex on the axis, and determine the upper and lower bound.
        for(const Vector3& vertex : vertices) {
            Vector3 projection = vertex.projectOnto(axis);

            if(projection.x > maximum.x) {
                maximum = projection;
            } else if(projection.x == maximum.x && projection.y > maximum.y) {
                maximum = projection;
            }

            if(projection.x < minimum.x) {
                minimum = projection;
            } else if(projection.x == minimum.x && projection.y < minimum.y) {
                minimum = projection;
            }
        }

        return Line2(minimum, maximum);
    }

    // Works only for lines that are projected on the same axis.
    static bool projectedLineIntersection(const Line2& him, const Line2& her) {
        const float himMax_x = std::max<float>(him.a.x, him.b.x);
        const float himMax_y = std::max<float>(him.a.y, him.b.y);
        const float himMin_x = std::min<float>(him.a.x, him.b.x);
        const float himMin_y = std::min<float>(him.a.y, him.b.y);

        const float herMax_x = std::max<float>(her.a.x, her.b.x);
        const float herMax_y = std::max<float>(her.a.y, her.b.y);
        const float herMin_x = std::min<float>(her.a.x, her.b.x);
        const float herMin_y = std::min<float>(her.a.y, her.b.y);

        return
            ((himMax_x <= herMax_x && himMax_x >= herMin_x) || (herMax_x <= himMax_x && herMax_x >= himMin_x))
            &&
            ((himMax_y <= herMax_y && himMax_y >= herMin_y) || (herMax_y <= himMax_y && herMax_y >= himMin_y))
        ;
    }
};


#endif	/* PROJECTION_H */

