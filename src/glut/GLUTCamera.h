#ifndef GLUTCAMERA_H_
#define GLUTCAMERA_H_

#include <core/Camera.h>

namespace phantom {
    class LIBEXPORT GLUTCamera : public Camera
    {
    public:
        GLUTCamera(int id);
        ~GLUTCamera();

        virtual void update(const float& elapsed);
        virtual Vector3 getViewCoordinates(Vector3* worldCoordinate);
        virtual Vector3 getWorldCoordinates(Vector3* viewCoordinate);
    };
}
#endif // !GLUTCAMERA_H_
