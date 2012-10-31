#include "KeyboardState.h"

namespace phantom {
    KeyboardState::KeyboardState() { };
    KeyboardState::~KeyboardState() { };

    void KeyboardState::handleEvent(char id, char newValue) {
        _keys[id] = newValue;
    }

    bool KeyboardState::isKeyDown(char id) {
        if(_keys[id] == 1)
            return true;
        else
            return false;
    }

    bool KeyboardState::isKeyUp(char id) {
        if(_keys[id] == 0)
            return true;
        else
            return false;
    }
}