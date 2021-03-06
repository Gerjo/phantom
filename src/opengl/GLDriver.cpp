#include <pch.h>
#include "GLDriver.h"
#include "GLRenderer.h"

#include <opengl/GLCamera.h>
#include <input/GLUTInput.h>
#include <graphics/ImageCache.h>
#include <openal/OpenALEngine.h>

namespace phantom{

    PhantomGame *GLDriver::_staticgame = nullptr;

    GLDriver::GLDriver(PhantomGame* game) : Driver(game) {
        _renderer = new GLRenderer(game);
        _audioEngine = new OpenALEngine(game);
        glutCloseFunc(closeListener);
        _input = new GLUTInput(game);
        _fontLibrary = new FreeTypeLibrary(_renderer);
        _staticgame = game;
    }

    GLDriver::~GLDriver(){
        delete _input;
        delete ImageCache::getInstance();
        delete _fontLibrary;
        delete _renderer;
        delete _audioEngine;
    }

    void GLDriver::setWindowTitle(string title) {
        glutSetWindowTitle(title.c_str());
    }

    Camera* GLDriver::createCamera(void) {
        Camera* cam = new GLCamera(0);
        return cam;
    }

    void GLDriver::closeListener() {
        _staticgame->exit(0);
    }

} /* namespace phantom */