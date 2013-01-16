#include <pch.h>
#include "Camera.h"
#include <core/Driver.h>

namespace phantom {
    Camera::Camera(int id) :
        _cameraID(id),
        _isActive(false),
        _rotation(0.0f, 0.0f, 0.0f),
        _viewPort(0.0f, 0.0f, 0.0f),
        _screenSize(0.0f, 0.0f, 0.0f) {

    }

    Camera::~Camera() {
        if(_isActive) {
            vector<Camera*> *cams = getDriver()->getActiveCameras();
            cams->erase(find(cams->begin(), cams->end(), this));
        }
    }

    int Camera::getCameraID() {
        return _cameraID;
    }

    bool Camera::isActive() {
        return _isActive;
    }

    Vector3 Camera::getWorldCoordinates(Vector3 viewCoordinate) {
        return _position + viewCoordinate;
    }

    Vector3& Camera::getScreenSize() {
        return _screenSize;
    }

    Vector3& Camera::getViewPort() {
        return _viewPort;
    }

    Vector3& Camera::getRotation() {
        return _rotation;
    }

    void Camera::setScreenSize(Vector3 s) {
        _screenSize = s;
    }

    void Camera::setViewPort(Vector3 vp) {
        _viewPort = vp;
    }

    void Camera::setRotation(Vector3 rot) {
        _rotation = rot;
    }

    void Camera::setParams() {
    }

    void Camera::setActive(bool value) {
        _isActive = value;
    }

}