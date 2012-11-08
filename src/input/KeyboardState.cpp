#include "KeyboardState.h"

namespace phantom {
    KeyboardState::KeyboardState() { for(unsigned i = 0; i < 255; ++i) _keys[i] = 0; };
    KeyboardState::~KeyboardState() { };

    void KeyboardState::handleEvent(char id, char newValue) {
        _keys[id] = newValue;
        if(newValue == 1)
            _changedDown.push_back(id);
        else
            _changedUp.push_back(id);
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

    std::vector<char> *KeyboardState::changes() {
        return &_changedDown;
    }
    
    std::vector<char> *KeyboardState::changesUp() {
        return &_changedUp;
    }
}