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

    Vector3 Box3::getCenter(void) {
        return Vector3(
                origin.x + size.x * 0.5,
                origin.y + size.y * 0.5,
                origin.z + size.z * 0.5);
    }

    bool Box3::contains(const Vector3& other) {
        // Note: see note at "testBounds".
        return
            other.x >= origin.x && other.x <= origin.x + size.x
            &&
            other.y >= origin.y && other.y <= origin.y + size.y
            &&
            other.z >= origin.z && other.z <= origin.z + size.z;
    }

    bool Box3::contains(const Vector3* other) {
        return contains(*other);
    }

    bool Box3::testBounds(const float& aMin, const float& bMin, const float& aMax, const float& bMax) const {

        // Note: we're testing for equality, too. This helps fix the "zero z width"
        // incase of a 2D box. I've done the same with the Vector3 detection. We
        // should have a discussion if this is actually desired. -- Gerjo

        // Two tests, a may bit in b, or b may fit in a.
        return
                aMin >= bMin && aMin <= bMax
                ||
                bMin >= aMin && bMin <= aMax;
    }

    bool Box3::intersect(const Line2& other) {
        // The axis along which we shall project.
        Vector3 axis = other.getNormal();

        // All vertices
        Vector3 vertices[] = {
            Vector3(origin.x, origin.y),
            Vector3(origin.x, origin.y + size.y),
            Vector3(origin.x + size.x, origin.y),
            Vector3(origin.x + size.x, origin.y + size.y)
        };

        const float inf = numeric_limits<float>::infinity();
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

        // Upper and lower bound form a line segment.
        Line2 line(min, max);
        Line2 meh(other.a.projectOnto(axis), other.b.projectOnto(axis));

        cout << line.toString() << endl;
        cout << meh.toString() << endl;

        bool r = line.naiveContains(meh);

        cout << "r" << r << endl;

        return line.naiveContains(meh);
    }

    bool Box3::intersect(const Box3& other) {
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

    string Box3::toString() {
        stringstream ss;
        ss << "[Box3] (x: " << origin.x << ", y:"  << origin.y << ", z:"  << origin.z;
        ss << ", width:" << size.x << ", height:" << size.y << ", depth:" << size.z << ")";

        return ss.str();
    }

    string Box3::toString2() {
        stringstream ss;
        ss << "box(" << origin.x << ", "  << origin.y;
        ss << ", " << size.x << ", " << size.y << ")";
        return ss.str();
    }

    Box3 Box3::getIntersectionNaive(const Box3& other) {
        return Box3(
            max(origin.x, other.origin.x),
            max(origin.y, other.origin.y),

            min(size.x, other.size.x),
            min(size.y, other.size.y)
        );
    }
}