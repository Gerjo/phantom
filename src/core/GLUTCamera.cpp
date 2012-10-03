#include <GL/freeglut.h>
#include "GLUTCamera.h"

namespace phantom {
    GLUTCamera::GLUTCamera(int id) : Camera(id) {
    }

    GLUTCamera::~GLUTCamera() {
    }

    Eigen::Vector3f GLUTCamera::getViewCoordinates(Eigen::Vector3f *world) {
        return Eigen::Vector3f();
    }

    Eigen::Vector3f GLUTCamera::getWorldCoordinates(Eigen::Vector3f *view) {
        return Eigen::Vector3f();
    }

    void GLUTCamera::update(const float &elapsed) {
        Composite::update(elapsed);
        if(isActive()) {
            Eigen::Vector3f viewPort = getViewPort();
            glViewport(0, 0, viewPort.x(), viewPort.y());
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            // Should become this:
            //glOrtho(0, 1280, 720, 0, -100, 100);
            glOrtho(0, 800, 450, 0, -100, 100);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        }
    }
}