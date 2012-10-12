#ifndef MOUSESTATE_H_
#define MOUSESTATE_H_

#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <CompileConfig.h>
#include <physics/Vector3.h>

namespace phantom {
    namespace Buttons {
        static unsigned char LEFT_MOUSE = 0;
        static unsigned char MIDDLE_MOUSE = 1;
        static unsigned char RIGHT_MOUSE = 2;
    }

    class LIBEXPORT MouseState {
    public:
        MouseState() : _buttonCount(5) {
            for(unsigned int i = 0; i <= _buttonCount; ++i)
                _buttons.push_back('0');
        };
        ~MouseState() { };

        void handleEvent(Vector3 newValue){ _mousePos = newValue;    }
        void handleEvent(char id, char newValue)  { _buttons[id] = newValue; }

        Vector3 getMousePosition() { return _mousePos; }
        bool isButtonDown(unsigned char id) {
            if(id <= _buttonCount) {
                std::cout << "mouse pos: " << _mousePos.toString() << std::endl;
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
        bool isButtonUp  (unsigned char id) { return !isButtonDown(id); }

    private:
        Vector3 _mousePos;
        unsigned int _buttonCount;
        std::vector<char> _buttons;
    };
}

#endif // MOUSESTATE_H_