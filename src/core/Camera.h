#ifndef CAMERA_H_
#define CAMERA_H_

#include <CompileConfig.h>
#include <core/Composite.h>
#include <physics/Vector3.h>
#include <iostream>
#include <physics/Vector3.h>

#include "Entity.h"

using namespace std;

namespace phantom {
    class LIBEXPORT Camera : public Entity {
        friend class Driver;
    public:
        Camera(int id) :
            _cameraID(id),
            _isActive(false),
            _rotation(0.0f, 0.0f, 0.0f),
            _viewPort(0.0f, 0.0f, 0.0f),
            _screenSize(0.0f, 0.0f, 0.0f)
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

        Vector3 getViewCoordinates(Vector3 viewCoordinate) {
            return _position + viewCoordinate;
        }

        Vector3& getScreenSize() {
            return _screenSize;
        }

        Vector3& getViewPort() {
            return _viewPort;
        }

        Vector3& getRotation() {
            return _rotation;
        }

        virtual void setScreenSize(Vector3 s) {
            _screenSize = s;
        }

        virtual void setViewPort(Vector3 vp) {
            _viewPort = vp;
        }

        virtual void setRotation(Vector3 rot) {
            _rotation = rot;
        }

        virtual void setParams() {
        }

    private:
        virtual void setActive(bool value) {
            _isActive = value;
        }

        bool _isActive;
        int _cameraID;
        Vector3 _rotation;
        Vector3 _viewPort;
        Vector3 _screenSize;
    };
}
#endif // !CAMERA_H_
