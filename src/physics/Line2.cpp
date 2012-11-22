#include "Line2.h"
#include "Vector3.h"

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

    bool Line2::eitherFit(const Line2& him, const Line2& her) {
        // TODO: can we cache data here?
        return (
            ((
                max(him.a.x, him.b.x) > max(her.a.x, her.b.x)
                &&
                min(him.a.x, him.b.x) < min(her.a.x, her.b.x)
            ) || (
                max(him.a.x, him.b.x) < max(her.a.x, her.b.x)
                &&
                min(him.a.x, him.b.x) > min(her.a.x, her.b.x)
            ))
            &&
            ((
                max(him.a.y, him.b.y) > max(her.a.y, her.b.y)
                &&
                min(him.a.y, him.b.y) < min(her.a.y, her.b.y)
            ) || (
                max(him.a.y, him.b.y) < max(her.a.y, her.b.y)
                &&
                min(him.a.y, him.b.y) > min(her.a.y, her.b.y)
            ))
        );
    }

    bool Line2::intersects(const Line2& other) const {
        Vector3 normalA = getNormal();
        Vector3 normalB = other.getNormal();

        return  eitherFit(a.projectOnto(normalB), b.projectOnto(normalB))
                   &&
                eitherFit(a.projectOnto(normalA), b.projectOnto(normalA));
    }
}