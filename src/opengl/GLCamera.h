#ifndef GLCAMERA_H_
#define GLCAMERA_H_

#include <core/Camera.h>

namespace phantom {
    class LIBEXPORT GLCamera : public Camera
    {
    public:
        GLCamera(int id);
        ~GLCamera();

        virtual void setParams();
    };
}
#endif // !GLCAMERA_H_
