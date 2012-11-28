#include "GLUTDriver.h"
#include "GLUTRenderer.h"

#include <GL/freeglut.h>
#include <glut/GLUTCamera.h>
#include <glut/GLUTInput.h>
#include <graphics/ImageCache.h>

namespace phantom{

    PhantomGame *GLUTDriver::_staticgame = nullptr;

    GLUTDriver::GLUTDriver(PhantomGame* game) : Driver(game) {
        _renderer = new GLUTRenderer(game);
        glutCloseFunc(closeListener);
        _input = new GLUTInput(game);
        _fontLibrary = new FreeTypeLibrary(_renderer);
        _staticgame = game;
    }

    GLUTDriver::~GLUTDriver(){
        delete _input;
        delete ImageCache::getInstance();
        delete _fontLibrary;
        delete _renderer;
    }

    void GLUTDriver::setWindowTitle(string title) {
        glutSetWindowTitle(title.c_str());
    }

    Camera* GLUTDriver::createCamera(void) {
        Camera* cam = new GLUTCamera(0);
        return cam;
    }

    void GLUTDriver::closeListener() {
        _staticgame->exit(0);
    }

} /* namespace phantom */