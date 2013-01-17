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
        /**
        * @return Returns the camera ID. This can be used to identify the camera.
        */
        int getCameraID();
        
        /**
        * @return Returns true if the camera is running.
        */
        bool isActive();
        
        /**
        * @return Returns the world coordinate.
        * @param viewCoordinate Position on the screen.
        */
        Vector3 getWorldCoordinates(Vector3 viewCoordinate);
        
        /**
        * @return Returns the screen size.
        */
        Vector3& getScreenSize();

        /**
        * @return Returns the camera's viewport.
        */
        Vector3& getViewPort();
        
        /**
        * @return Returns the camera's rotation.
        */
        Vector3& getRotation();
        
        /**
        * Sets the screen size.
        *
        * @param s The new screen size.
        */
        virtual void setScreenSize(Vector3 s);

        /**
        * Set the view port.
        *
        * @param vp The new view port.
        */
        virtual void setViewPort(Vector3 vp);

        /**
        * Set the camera rotation.
        *
        * @param rot The camera rotation.
        */
        virtual void setRotation(Vector3 rot);
        
        /**
        * Function called by the renderer for setting the display properties.
        */
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
