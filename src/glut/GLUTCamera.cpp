#include <GL/freeglut.h>
#include "GLUTCamera.h"

namespace phantom {
    GLUTCamera::GLUTCamera(int id) : Camera(id) {
    }

    GLUTCamera::~GLUTCamera() {
    }

    void GLUTCamera::update(const float &elapsed) {
        Composite::update(elapsed);

        if(isActive()) {
            const Vector3& pos = getPosition();

            Vector3 viewPort = getViewPort();
            glViewport(0, 0, viewPort.x, viewPort.y);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            // Should become this:
            //glOrtho(0, 1280, 720, 0, -100, 100);
            glOrtho(0, 800, 450, 0, -100, 100);
            glTranslatef(-pos.x, -pos.y, -pos.z);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        }
    }
}