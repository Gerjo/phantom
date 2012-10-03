#ifndef CAMERA_H_
#define CAMERA_H_

#include <CompileConfig.h>
#include <Eigen/Geometry>

namespace phantom {
    class LIBEXPORT Camera {
    public:
        Camera(int id) :
            _cameraID(id),
            _isActive(true),
            _position(0.0f, 0.0f, 0.0f),
            _rotation(0.0f, 0.0f, 0.0f)
        {
        }

        virtual ~Camera() {
        }

        int getCameraID() {
            return _cameraID;
        }

        bool isActive() {
            return _active;
        }

        virtual Eigen::Vector3f getViewCoordinates(Eigen::Vector3f *worldCoordinate) = 0;
        virtual Eigen::Vector3f getWorldCoordinates(Eigen::Vector3f *viewCoordinate) = 0;

        virtual Eigen::Vector3f getPosition() { 
            return _position;
        }
        virtual Eigen::Vector3f getRotation() {
            return _rotation;
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
    };
}
#endif // !CAMERA_H_
