#include "MouseState.h"

namespace phantom {
    MouseState::MouseState() : _buttonCount(5) {
        for(unsigned int i = 0; i <= _buttonCount; ++i)
            _buttons.push_back('0');
    }

    MouseState::~MouseState() { }

    void MouseState::handleEvent(Vector3 newValue) {
        _mousePos = newValue;
    }

    void MouseState::handleEvent(char id, char newValue) {
        _buttons[id] = newValue;
    }

    Vector3 MouseState::getMousePosition() {
        return _mousePos;
    }

    bool MouseState::isButtonDown(unsigned char id) {
        if(id <= _buttonCount) {
            return _buttons[id] == 1;
        }
        else {
            for(unsigned int i = _buttonCount; i <= id; ++i) {
                _buttons.push_back('0');
            }
            _buttonCount = id;
            return _buttons[id] == 1;
        }
    }

    bool MouseState::isButtonUp(unsigned char id) { 
        return !isButtonDown(id); 
    }
}