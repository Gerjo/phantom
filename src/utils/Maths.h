#ifndef MATHS_H_
#define MATHS_H_

#include <math.h>

#include <physics/Vector3.h>
#include <physics/Box3.h>

namespace phantom {
    namespace maths {
        //static Vector3 rotationToDirection(const float& angle);
        static float directionToRotation(phantom::Vector3* direction) {
            return atan2(direction->y, direction->x) * 180 / 3.14159f;
        }
    }
}

#endif