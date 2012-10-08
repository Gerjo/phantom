#include "GLUTDriver.h"
#include "GLUTRenderer.h"
#include <glut/GLUTCamera.h>
#include <glut/GLUTInput.h>

namespace phantom{

    GLUTDriver::GLUTDriver(PhantomGame* game) : Driver(game) {
        _renderer = new GLUTRenderer(&game->getViewPort(), &game->getWorldSize());
        _input    = new GLUTInput(game);
    }

    GLUTDriver::~GLUTDriver(){
        delete _input;
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