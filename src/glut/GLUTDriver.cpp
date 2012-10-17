#include "GLUTDriver.h"
#include "GLUTRenderer.h"

#include <gl/freeglut.h>
#include <glut/GLUTCamera.h>
#include <glut/GLUTInput.h>
#include <graphics/ImageCache.h>

namespace phantom{

    GLUTDriver::GLUTDriver(PhantomGame* game) : Driver(game) {
        _renderer = new GLUTRenderer(game);
        _input    = new GLUTInput(game);
    }

    GLUTDriver::~GLUTDriver(){
        delete _input;
        delete ImageCache::getInstance();
        delete _renderer;
    }

    void GLUTDriver::setWindowTitle(string title) {
        glutSetWindowTitle(title.c_str());
    }

    void GLUTDriver::onUpdate(float elapsed){
        _game->update(elapsed);
        _renderer->renderLoop(&_game->getGameStates());
    }

    void GLUTDriver::onRender() {

    }

    Camera* GLUTDriver::createCamera(void) {
        Camera* cam = new GLUTCamera(0);
        return cam;
    }

} /* namespace phantom */