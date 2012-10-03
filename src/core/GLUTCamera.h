#ifndef GLUTCAMERA_H_
#define GLUTCAMERA_H_

#include "Camera.h"

namespace phantom {
    class GLUTCamera : public Camera
    {
    public:
        GLUTCamera(int id);
        ~GLUTCamera();

        virtual void update(const float& elapsed);
        virtual Eigen::Vector3f getViewCoordinates(Eigen::Vector3f *worldCoordinate);
        virtual Eigen::Vector3f getWorldCoordinates(Eigen::Vector3f *viewCoordinate);
    };
}
#endif // !GLUTCAMERA_H_
