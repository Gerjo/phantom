#include "Line2.h"
#include "Vector3.h"
#include "Projection.h"

namespace phantom {

    Line2::Line2(void) : a(0.0f, 0.0f, 0.0f), b(0.0f, 0.0f, 0.0f) {

    }

    Line2::Line2(const float x1, const float y1, const float x2, const float y2) :
        a(x1, y1, 0.0f), b(x2, y2, 0.0f) {

    }

    Line2::Line2(const Vector3& min, const Vector3& max) : a(min), b(max) {

    }

    Vector3 Line2::getNormal(void) const {
        // NB: instead of calling methods, we can simply inline all
        // the math involved here.
        Vector3 direction = getDirection();

        return direction.perp().normalize();
    }

    Vector3 Line2::getDirection(void) const {
        // A to B is B - A:
        Vector3 direction (
            b.x - a.x,
            b.y - a.y,
            b.z - a.z
        );

        return direction;
    }

    Line2 Line2::projectOnto(const Vector3& axis) const {
        // NB: should it matter, we can inline the math.
        const Vector3 aProjected = a.projectOnto(axis);
        const Vector3 bProjected = b.projectOnto(axis);

        return Line2(
            aProjected,
            bProjected
        );
    }

    bool Line2::intersects(const Line2& other) const {
        Vector3 normalA = getNormal();
        Vector3 normalB = other.getNormal();

        // Account for A->dot(B) == 0.
        if(normalA == normalB) {
            return Projection::projectedLineIntersection(*this, other);
        }

        return Projection::projectedLineIntersection(projectOnto(normalB), other.projectOnto(normalB))
                &&
               Projection::projectedLineIntersection(projectOnto(normalA), other.projectOnto(normalA));
    }

    std::string Line2::toString(void) const {
        return "line(" +
                std::to_string(a.x) + "," +
                std::to_string(a.y) + "," +
                std::to_string(b.x) + "," +
                std::to_string(b.y) + ")";
    }


    bool Line2::operator== (const Line2& v) const {
        return  a.x == v.a.x && a.y == v.a.y && a.z == v.a.z
                &&
                b.x == v.b.x && b.y == v.b.y && b.z == v.b.z;
    }

    bool Line2::operator!= (const Line2& v) const {
        return !(*this == v);
    }
}
