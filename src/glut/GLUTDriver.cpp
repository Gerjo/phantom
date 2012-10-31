#include "GLUTDriver.h"
#include "GLUTRenderer.h"

#include <GL/freeglut.h>
#include <glut/GLUTCamera.h>
#include <glut/GLUTInput.h>
#include <graphics/ImageCache.h>

namespace phantom{

    GLUTDriver::GLUTDriver(PhantomGame* game) : Driver(game) {
        _renderer = new GLUTRenderer(game);
        _input = new GLUTInput(game);
        _fontLibrary = new FreeTypeLibrary(_renderer);
    }

    GLUTDriver::~GLUTDriver(){
        delete _input;
        delete ImageCache::getInstance();
        delete _renderer;
        delete _fontLibrary;
    }

    void GLUTDriver::setWindowTitle(string title) {
        glutSetWindowTitle(title.c_str());
    }

    Camera* GLUTDriver::createCamera(void) {
        Camera* cam = new GLUTCamera(0);
        return cam;
    }

} /* namespace phantom */