#ifndef BOX3_H
#define BOX3_H

#include <physics/Vector3.h>
#include <CompileConfig.h>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

namespace phantom{
    class LIBEXPORT Box3{
    public:
        Box3();
        Box3(float x, float y, float width, float height);

        Box3(Vector3 origin, Vector3 size);
        bool intersect(const Box3& other);
        bool contains(const Vector3& other);
        bool contains(const Vector3* other);

        Vector3 origin;
        Vector3 size;

        void repair(void);
        string toString(void);
    private:
        bool testBounds(const float& aMin, const float& bMin, const float& aMax, const float& bMax) const;

    };

} /* namespace phantom */

#endif /* BOX3_H */