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

     bool Box3::intersect(const Box3& other) {
         // Made these vars so in the future we can return a new box instead of just true/false.
         float box1_top = this->origin.y;
         float box2_top = other.origin.y;

         float box1_bottom = this->origin.y + this->size.y;
         float box2_bottom = other.origin.y + other.size.y;

         float box1_left = this->origin.x;
         float box2_left = other.origin.y;

         float box1_right = this->origin.x + this->size.x;
         float box2_right = other.origin.x + other.size.y;

         unsigned int collisionCount = 0;
         if(box2_left > box1_right) collisionCount++;
         if(box2_right < box1_left) collisionCount++;
         if(box2_top > box1_bottom) collisionCount++;
         if(box2_bottom < box1_top) collisionCount++;

         return (collisionCount >= 2);
     }
}