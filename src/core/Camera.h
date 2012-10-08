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
        friend Driver;
    public:
        Camera(int id) :
            _cameraID(id),
            _isActive(true),
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

        Vector3 getWorldCoordinates(Vector3 viewCoordinate) {
            return _position + viewCoordinate;
        }

        Vector3& getWorldSize() {
            return _worldSize;
        }

        Vector3& getViewPort() {
            return _viewPort;
        }

        Vector3& getRotation() {
            return _rotation;
        }

        virtual void setWorldSize(Vector3 ws) {
            _worldSize = ws;
        }

        virtual void setViewPort(Vector3 vp) {
            _viewPort = vp;
        }

        virtual void setRotation(Vector3 rot) {
            _rotation = rot;
        }

    private:
        virtual void setActive(bool value) {
            _isActive = value;
        }

        bool _isActive;
        int _cameraID;
        Vector3 _rotation;
        Vector3 _viewPort;
        Vector3 _worldSize;
    };
}
#endif // !CAMERA_H_
