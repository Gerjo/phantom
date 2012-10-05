#include "Box3.h"
namespace phantom{
    Box3::Box3() {

    }

    Box3::Box3(float x, float y, float width, float height) {
        origin.x = x;
        origin.y = y;
        size.x   = width;
        size.y   = height;
    }

    Box3::Box3(Vector3 origin, Vector3 size): origin(origin), size(size){

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

     bool Box3::testBounds(float aMin, float bMin, float aMax, float bMax) {

         // Note: we're testing for equality, too. This helps fix the "zero z width"
         // incase of a 2D box. I've done the same with the Vector3 detection. We
         // should have a discussion if this is actually desired. -- Gerjo

         // Two tests, a may bit in b, or b may fit in a.
         return
                 aMin >= bMin && aMin <= bMax
                 ||
                 bMin >= aMin && bMin <= aMax;
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
}