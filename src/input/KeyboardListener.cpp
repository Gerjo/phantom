#include <pch.h>
#include "KeyboardListener.h"
#include <utils/PhantomException.h>
#include <core/Composite.h>
#include <core/Driver.h>

namespace phantom {

    KeyboardListener *KeyboardListener::INSTANCE = nullptr;

    KeyboardListener::KeyboardListener(Driver *driver, PhantomGame *game) : _locked(false), _driver(driver), _game(game), _key(nullptr) {
        if(INSTANCE == 0) {
            INSTANCE = this;
        }
        else
            throw PhantomException("Keyboard not found. Press F1 to continue.");
    }

    KeyboardListener::~KeyboardListener() {
    }

    void KeyboardListener::update() {
        if(!KeyboardListener::INSTANCE->isLocked()) {
            // Allows us to quick exit the game.        
            if(_driver->getInput()->getKeyboardState()->isKeyDown(27)) {
                _game->exit(0);
                return;
            }
        }
    }

    KeyboardState *KeyboardListener::lock(Composite* keycomp) {
        if(INSTANCE->_locked) return nullptr;
        else {
            INSTANCE->_locked = true;
            INSTANCE->_key = keycomp;
            return INSTANCE->_driver->getInput()->getKeyboardState();
        }
    }

    void KeyboardListener::unlock(Composite* keycomp) {
        if(keycomp == INSTANCE->_key) {
            INSTANCE->_locked = false;
        }
    }
}
