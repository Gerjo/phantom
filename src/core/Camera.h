#ifndef CAMERA_H_
#define CAMERA_H_

#include <CompileConfig.h>
#include <Eigen/Geometry>

#include <core/Composite.h>

#include <iostream>
using namespace std;

namespace phantom {
    class LIBEXPORT Camera : public Composite {
    public:
        Camera(int id) :
            _cameraID(id),
            _isActive(true),
            _position(200.0f, 20.0f, 0.0f),
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

        virtual Eigen::Vector3f getViewCoordinates(Eigen::Vector3f *worldCoordinate) = 0;
        virtual Eigen::Vector3f getWorldCoordinates(Eigen::Vector3f *viewCoordinate) = 0;

        const Eigen::Vector3f& getViewPort() {
            return _viewPort;
        }

        const Eigen::Vector3f& getPosition() {
            return _position;
        }
        const Eigen::Vector3f& getRotation() {
            return _rotation;
        }

        virtual void setViewPort(Eigen::Vector3f vp) {
            _viewPort = vp;
        }

        virtual void setPosition(Eigen::Vector3f pos) {
            _position = pos;
        }
        virtual void setRotation(Eigen::Vector3f rot) {
            _rotation = rot;
        }

    private:
        bool _isActive;
        int _cameraID;
        Eigen::Vector3f _position;
        Eigen::Vector3f _rotation;
        Eigen::Vector3f _viewPort;
    };
}
#endif // !CAMERA_H_
