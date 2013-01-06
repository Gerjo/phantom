#include <pch.h>
#include <GL/freeglut.h>
#include "GLCamera.h"
#include "core/PhantomGame.h"

namespace phantom {
    GLCamera::GLCamera(int id) : Camera(id) {
        setViewPort(getPhantomGame()->getViewPort());
        setScreenSize(getPhantomGame()->getScreenSize());
    }

    GLCamera::~GLCamera() {
    }

    void GLCamera::setParams() {
        const Vector3& pos = getPosition();

        const Vector3& screenSize = getScreenSize();
        const Vector3& viewPort = getViewPort();

        glViewport(0, 0, static_cast<int>(screenSize.x), static_cast<int>(screenSize.y));
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glOrtho(0, viewPort.x, viewPort.y, 0, -100, 100);
        glTranslatef(-pos.x, -pos.y, -pos.z);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
}