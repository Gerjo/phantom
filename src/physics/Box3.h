#ifndef BOX3_H
#define BOX3_H

#include <physics/Vector3.h>
#include <CompileConfig.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <physics/Line2.h>
#include <limits>
#include <physics/Projection.h>
#include <array>

using namespace std;

namespace phantom{
    class LIBEXPORT Box3{
    public:
        Box3();
        Box3(float x, float y, float width, float height);
        Box3(Vector3 origin, Vector3 size);

        bool intersects(const Box3& other) const;
        bool intersects(const Line2& other) const;
        bool intersects(const Vector3& other) const;
        bool intersects(const Vector3* other) const;

        // This function is naive b.c. it assumes both boxes are repaired
        // and actually have an intersection. If neither conditions are met,
        // then you should not use this, continue with writing a "not so naive"
        // method to solve this problem. -- Gerjo
        Box3 intersection(const Box3& other) const;
        Vector3 intersection(const Line2& other) const;

        Vector3 getCenter(void) const;

        Vector3 origin;
        Vector3 size;
        void repair(void);
        string toString(void);
        string toString2(void);

        friend ostream& operator<<(ostream& o, const Box3& b){
            o << "[Box3] (x: " << b.origin.x << ", y:"  << b.origin.y << ", z:"  << b.origin.z;
            o << ", width:" << b.size.x << ", height:" << b.size.y << ", depth:" << b.size.z << ")";
            return o;
        }
    private:
        bool testBounds(const float& aMin, const float& bMin, const float& aMax, const float& bMax) const;

    };

} /* namespace phantom */

#endif /* BOX3_H */