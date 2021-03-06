#ifndef LINE2_H_PHANTOM
#define	LINE2_H_PHANTOM

#include <algorithm>
#include <physics/Line2.h>
#include "Vector3.h"
#include <CompileConfig.h>

// tmp
#include <iostream>
using std::cout;
using std::endl;

namespace phantom {
    class LIBEXPORT Line2 {
    public:
        Line2(void);
        Line2(const float x1, const float y1, const float x2, const float y2);
        Line2(const Vector3& a, const Vector3& b);

        bool operator== (const Line2& v) const;
        bool operator!= (const Line2& v) const;

        Vector3 getNormal(void) const;
        Vector3 getDirection(void) const;
        Line2 projectOnto(const Vector3& axis) const;
        bool intersects(const Line2& other) const;

        Vector3 intersection(const Line2& other) const;

        std::string toString(void) const;

        Vector3 a;
        Vector3 b;

    private:

    };
}
#endif	/* LINE2_H_PHANTOM */

