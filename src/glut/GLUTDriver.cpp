#include "GLUTDriver.h"
#include "GLUTRenderer.h"
#include <glut/GLUTCamera.h>
#include <glut/GLUTInputState.h>
namespace phantom{

    GLUTDriver::GLUTDriver(PhantomGame* game) : Driver(game) {
        _renderer = new GLUTRenderer(_game->getWidth(), _game->getHeight());

        _camera = new GLUTCamera(0);
        _camera->setViewPort(Eigen::Vector3f((float)game->getWidth(), (float)game->getHeight(), 0.0f));
    }

    GLUTDriver::~GLUTDriver(){

    }

    void GLUTDriver::onUpdate(float elapsed){
        _game->update(elapsed);

        _camera->update(elapsed);
        _renderer->renderLoop(&_game->getGameStates());
    }

    void GLUTDriver::onRender() {

    }

} /* namespace phantom */