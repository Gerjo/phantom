#include <GL/freeglut.h>
#include "GLUTCamera.h"
#include "core/PhantomGame.h"

namespace phantom {
    GLUTCamera::GLUTCamera(int id) : Camera(id) {
        setViewPort(getGame()->getViewPort());
        setWorldSize(getGame()->getWorldSize());
    }

    GLUTCamera::~GLUTCamera() {
    }

    void GLUTCamera::update(const float &elapsed) {
        Composite::update(elapsed);

        if(isActive()) {
            const Vector3& pos = getPosition();

            const Vector3& viewPort = getViewPort();
            const Vector3& worldSize = getWorldSize();

            glViewport(0, 0, static_cast<int>(viewPort.x), static_cast<int>(viewPort.y));
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            glOrtho(0, worldSize.x, worldSize.y, 0, -100, 100);
            glTranslatef(-pos.x, -pos.y, -pos.z);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        }
    }
}