#include "GLUTDriver.h"
#include "GLUTRenderer.h"
#include <input/GLUTInputState.h>
namespace phantom{
   
    GLUTDriver::GLUTDriver(){

    }
    GLUTDriver::~GLUTDriver(){

    }
    void GLUTDriver::setGame(PhantomGame* game){
        this->game = game;
        renderer = new GLUTRenderer(game->getWidth(), game->getHeight());
        inputState = new GLUTInputState();
        game->setRenderer(renderer);
        game->addComponent(inputState);
    }
    void GLUTDriver::onUpdate(float elapsed){
        game->update(elapsed);
    }
    void GLUTDriver::onRender(){
    }

} /* namespace phantom */