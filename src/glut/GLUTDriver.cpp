#include "GLUTDriver.h"
#include "GLUTRenderer.h"
#include <glut/GLUTCamera.h>
#include <glut/GLUTInputState.h>
namespace phantom{

    GLUTDriver::GLUTDriver(PhantomGame* game) : Driver(game) {
        renderer = new GLUTRenderer(_game->getWidth(), _game->getHeight());
        _game->setRenderer(renderer);

        camera = new GLUTCamera(0);
        camera->setViewPort(Eigen::Vector3f((float)game->getWidth(), (float)game->getHeight(), 0.0f));
        _game->setCamera(camera);
    }

    GLUTDriver::~GLUTDriver(){

    }

    void GLUTDriver::setGame(){

        //inputState = new GLUTInputState();
        //camera = new GLUTCamera(0);
        //camera->setViewPort(Eigen::Vector3f((float)game->getWidth(), (float)game->getHeight(), 0.0f));

        //_game->setCamera(camera);
        _game->setRenderer(renderer);
        //_game->addComponent(inputState);
    }

    void GLUTDriver::onUpdate(float elapsed){
        _game->update(elapsed);

        camera->update(elapsed);
        renderer->renderLoop(&_game->getGameStates());
    }

    void GLUTDriver::onRender() {

    }

} /* namespace phantom */