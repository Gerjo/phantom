#include "Box3.h"
#include "Line2.h"
namespace phantom{
    Box3::Box3() : origin(0.0f, 0.0f, 0.0f), size(0.0f, 0.0f, 0.0f) {

    }

    Box3::Box3(float x, float y, float width, float height) {
        origin.x = x;
        origin.y = y;
        size.x   = width;
        size.y   = height;
    }

    Box3::Box3(Vector3 origin, Vector3 size): origin(origin), size(size){

    }

    Vector3 Box3::getCenter(void) const {
        return Vector3(
                origin.x + size.x * 0.5,
                origin.y + size.y * 0.5,
                origin.z + size.z * 0.5);
    }

    bool Box3::intersects(const Vector3& other) const {
        // Note: see note at "testBounds".
        return
            other.x >= origin.x && other.x <= origin.x + size.x
            &&
            other.y >= origin.y && other.y <= origin.y + size.y
            &&
            other.z >= origin.z && other.z <= origin.z + size.z;
    }

    bool Box3::intersects(const Vector3* other) const {
        return intersects(*other);
    }

    bool Box3::testBounds(const float& aMin, const float& bMin, const float& aMax, const float& bMax) const {

        // Note: we're testing for equality, too. This helps fix the "zero z width"
        // incase of a 2D box. I've done the same with the Vector3 detection. We
        // should have a discussion if this is actually desired. -- Gerjo

        // Two tests, a may fit in b, or b may fit in a.
        return
                (aMin >= bMin && aMin <= bMax)
                ||
                (bMin >= aMin && bMin <= aMax);
    }

    bool Box3::intersects(const Line2& other) const {

        Vector3 normals[] = {
            other.getNormal(),

            // Hardcoded normals for an axis aligned box
            Vector3(0.0f, 1.0f, 0.0f),
            Vector3(1.0f, 0.0f, 0.0f)
        };

        Projection::Group boxVertices;
        boxVertices.push_back(Vector3(origin.x, origin.y));
        boxVertices.push_back(Vector3(origin.x, origin.y + size.y));
        boxVertices.push_back(Vector3(origin.x + size.x, origin.y));
        boxVertices.push_back(Vector3(origin.x + size.x, origin.y + size.y));


        Projection::Group lineVertices;
        lineVertices.push_back(other.a);
        lineVertices.push_back(other.b);

        for(const Vector3& axis : normals) {
            //cout << "ray" << axis.toString2().substr(6, axis.toString2().length()) << endl;
            Line2 a = Projection::project(axis, boxVertices);
            Line2 b = Projection::project(axis, lineVertices);


            if(!Projection::projectedLineIntersection(a, b)) {
                // cout << "false: " << " for " << a.toString() << " vs " << b.toString() << endl;
                return false;
            } else {
                //cout << "true: " << " for " << a.toString() << " vs " << b.toString() << endl;
            }
        }

        return true;
    }

    bool Box3::intersects(const Box3& other) const {
        // Test each dimension:
        return
           testBounds(origin.x, other.origin.x, origin.x + size.x, other.origin.x + other.size.x)
           &&
           testBounds(origin.y, other.origin.y, origin.y + size.y, other.origin.y + other.size.y)
           &&
           testBounds(origin.z, other.origin.z, origin.z + size.z, other.origin.z + other.size.z)
        ;
    }

    void Box3::repair(void) {
        if(size.x < 0) {
            origin.x += size.x;
            size.x = abs(size.x);
        }

        if(size.y < 0) {
            origin.y += size.y;
            size.y = abs(size.y);
        }

        if(size.z < 0) {
            origin.z += size.z;
            size.z = abs(size.z);
        }
    }

    string Box3::toString() const {
        stringstream ss;
        ss << "[Box3] (x: " << origin.x << ", y:"  << origin.y << ", z:"  << origin.z;
        ss << ", width:" << size.x << ", height:" << size.y << ", depth:" << size.z << ")";

        return ss.str();
    }

    string Box3::toString2() const {
        stringstream ss;
        ss << "box(" << origin.x << ", "  << origin.y;
        ss << ", " << size.x << ", " << size.y << ")";
        return ss.str();
    }

    Box3 Box3::intersection(const Box3& other) const {
        return Box3(
            max(origin.x, other.origin.x),
            max(origin.y, other.origin.y),

            min(size.x, other.size.x),
            min(size.y, other.size.y)
        );
    }


    /*           0
     *          TOP
     *     +-----------+
     *   R |           | L
     * 3 I |           | E 1
     *   G |           | F
     *   H |           | T
     *   T |           |
     *     +-----------+
     *         BOTTOM
     *            2
     *
     * We generate these line segments on the fly, which does leave room
     * for optimization. Quite possibly we could export a box to a polygon
     * and reuse that polygon within our math calculations. For now this is
     * OK since it's just an experiment. -- Gerjo
     *
     */
    Vector3 Box3::intersection(const Line2& other) const {
        std::array<Line2, 4> edges;
        edges[0].a   = origin;
        edges[0].b.x = origin.x + size.x;
        edges[0].b.y = origin.y;

        edges[1].a   = edges[0].b;
        edges[1].b.x = edges[0].b.x;
        edges[1].b.y = origin.y + size.y;

        edges[3].a   = origin;
        edges[3].b.x = origin.x;
        edges[3].b.y = origin.y + size.y;

        edges[2].a  = edges[3].b;
        edges[2].b  = edges[1].b;

        Vector3 intersection;

        for(const Line2& edge : edges) {
            intersection = other.intersection(edge);

            if(intersection.isFinite()) {
                return intersection;
            }
        }

        return intersection;
    }
}
