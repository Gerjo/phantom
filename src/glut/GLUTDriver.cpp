#include "GLUTDriver.h"
#include "GLUTRenderer.h"
#include <glut/GLUTCamera.h>
#include <glut/GLUTInputState.h>
namespace phantom{

    GLUTDriver::GLUTDriver(PhantomGame* game) : Driver(game) {
        _renderer = new GLUTRenderer(_game->getWidth(), _game->getHeight());
    }

    GLUTDriver::~GLUTDriver(){

    }

    void GLUTDriver::onUpdate(float elapsed){
        _game->update(elapsed);
        _renderer->renderLoop(&_game->getGameStates());
    }

    void GLUTDriver::onRender() {

    }

    Camera* GLUTDriver::createCamera(void) {
        Camera* cam = new GLUTCamera(0);
        cam->setViewPort(Eigen::Vector3f((float)_game->getWidth(), (float)_game->getHeight(), 0.0f));
        return cam;
    }

} /* namespace phantom */