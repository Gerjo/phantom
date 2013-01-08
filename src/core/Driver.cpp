#include <pch.h>
#include "Driver.h"

#include <input/KeyboardListener.h>

namespace phantom{

    Driver::Driver(PhantomGame* game) : _game(game) {
        _renderer = 0;
        _fontLibrary = 0;
        _audioEngine = 0;
        _audio = new Sounds();
        _keyboard = new KeyboardListener(this, game);
    }

    Driver::~Driver(){
        delete _audio;
        delete _keyboard;
    }

    void Driver::setWindowTitle(string title) {
    }

    void Driver::onUpdate(PhantomTime time) {
        _keyboard->update();
        _input->getKeyboardState()->changes()->clear();
        _input->getKeyboardState()->changesUp()->clear();
    }

    void Driver::onRender() {
        _renderer->renderLoop(&_game->getGameStates());
    }

    vector<Camera*>* Driver::getActiveCameras() {
        return &_activeCameras;
    }

    void Driver::enableCamera(Camera *cam) {
        cam->setActive(true);
        _activeCameras.push_back(cam);
    }

    void Driver::disableCamera(Camera *cam) {
        cam->setActive(false);
        for(vector<Camera*>::iterator it = _activeCameras.begin(); it != _activeCameras.end();) {
            if(*it == cam) {
                it = _activeCameras.erase(it);
            }
            else
                ++it;
        }
    }

    Input* Driver::getInput() {
        return _input;
    }

    Renderer *Driver::getRenderer() {
        return _renderer;
    }

    Sounds *Driver::getAudio() {
        return _audio;
    }

    AudioEngine *Driver::getAudioEngine() {
        return _audioEngine;
    }

    FreeTypeLibrary *Driver::getFontLibrary() {
        return _fontLibrary;
    }

    void Driver::addCamToList(Camera *cam) {
        _cameras.push_back(cam);
    }
}