#ifndef CAMERA_H_
#define CAMERA_H_

#include <CompileConfig.h>
#include <core/Composite.h>
#include <physics/Vector3.h>
#include <iostream>
#include <physics/Vector3.h>

using namespace std;

namespace phantom {
    class LIBEXPORT Camera : public Composite {
    public:
        Camera(int id) :
            _cameraID(id),
            _isActive(true),
            _position(0.0f, 0.0f, 0.0f),
            _rotation(0.0f, 0.0f, 0.0f),
            _viewPort(0.0f, 0.0f, 0.0f)
        {

        }

        virtual ~Camera() {
        }

        int getCameraID() {
            return _cameraID;
        }

        bool isActive() {
            return _isActive;
        }

        virtual Vector3 getViewCoordinates(Vector3 *worldCoordinate) = 0;
        virtual Vector3 getWorldCoordinates(Vector3 *viewCoordinate) = 0;

        Vector3& getViewPort() {
            return _viewPort;
        }

        Vector3& getPosition() {
            return _position;
        }
        Vector3& getRotation() {
            return _rotation;
        }

        virtual void setViewPort(Vector3 vp) {
            _viewPort = vp;
        }

        virtual void setPosition(Vector3 pos) {
            _position = pos;
        }
        virtual void setRotation(Vector3 rot) {
            _rotation = rot;
        }

    private:
        bool _isActive;
        int _cameraID;
        Vector3 _position;
        Vector3 _rotation;
        Vector3 _viewPort;
    };
}
#endif // !CAMERA_H_
