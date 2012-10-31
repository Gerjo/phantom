#include "Driver.h"

namespace phantom{

    Driver::Driver(PhantomGame* game) : _game(game) {
        _camera = 0;
        _renderer = 0;
        _fontLibrary = 0;
    }

    Driver::~Driver(){
    }

    void Driver::setWindowTitle(string title) {
    }

    void Driver::onUpdate(Time time) {
        _game->update(time);
        _input->getKeyboardState()->changes()->clear();
        _input->getKeyboardState()->changesUp()->clear();
    }

    void Driver::onRender() {
        _renderer->renderLoop(&_game->getGameStates());
    }

    Camera* Driver::getActiveCamera() {
        if(_camera != 0)
            return _camera;
        else
            throw PhantomException("There is no active camera set yet.");
    }

    void Driver::setActiveCamera(Camera *cam) {
        if(_camera != 0)
            _camera->setActive(false);
        _camera = cam;
        _camera->setActive(true);
    }

    Input* Driver::getInput() {
        return _input;
    }

    Renderer *Driver::getRenderer() {
        return _renderer;
    }

    FreeTypeLibrary *Driver::getFontLibrary() {
        return _fontLibrary;
    }
}