#ifndef CAMERA_H_
#define CAMERA_H_

#include <CompileConfig.h>
#include <core/Composite.h>
#include <physics/Vector3.h>

using namespace std;

namespace phantom {
    class LIBEXPORT Camera : public Composite {
        friend class Driver;
    public:
        Camera(int id);
        virtual ~Camera();

        int getCameraID();
        bool isActive();
        Vector3 getWorldCoordinates(Vector3 viewCoordinate);
        Vector3& getScreenSize();
        Vector3& getViewPort();
        Vector3& getRotation();
        virtual void setScreenSize(Vector3 s);
        virtual void setViewPort(Vector3 vp);
        virtual void setRotation(Vector3 rot);
        virtual void setParams();

    private:
        virtual void setActive(bool value);

        bool _isActive;
        int _cameraID;
        Vector3 _rotation;
        Vector3 _viewPort;
        Vector3 _screenSize;
    };
}
#endif // !CAMERA_H_
