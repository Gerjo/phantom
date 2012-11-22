#ifndef LINE2_H_PHANTOM
#define	LINE2_H_PHANTOM

#include <physics/Line2.h>

namespace phantom {
    class Line2 {
    public:
        Line2(void);
        Line2(const float x1, const float y1, const float x2, const float y2);
        Line2(const Vector3& a, const Vector3& b);

        Vector3 getNormal(void) const;
        Vector3 getDirection(void) const;
        Line2 projectOnto(const Vector3& axis) const;
        bool intersects(const Line2& other) const;

    private:
        Vector3 a;
        Vector3 b;

        // If you're using this, you are probably doing something wrong.
        bool eitherFit(const Line2& him, const Line2& her);
    };
}
#endif	/* LINE2_H_PHANTOM */

