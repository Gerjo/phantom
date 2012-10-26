#ifndef GLUTCAMERA_H_
#define GLUTCAMERA_H_

#include <core/Camera.h>

namespace phantom {
    class LIBEXPORT GLUTCamera : public Camera
    {
    public:
        GLUTCamera(int id);
        ~GLUTCamera();

        virtual void update(const Time& time);
    };
}
#endif // !GLUTCAMERA_H_
