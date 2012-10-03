#ifndef MOUSESTATE_H_
#define MOUSESTATE_H_

#include <Eigen/Geometry>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <CompileConfig.h>

namespace phantom {
    class LIBEXPORT MouseState {
    public:
        MouseState() : _buttonCount(5) {
            for(unsigned int i = 0; i <= _buttonCount; ++i)
                _buttons.push_back('0');
        };
        ~MouseState() { };

        void handleEvent(Eigen::Vector3f newValue){ _mousePos = newValue;    }
        void handleEvent(char id, char newValue)  { _buttons[id] = newValue; }

        const Eigen::Vector3f& getMousePosition() { return _mousePos; }
        bool isButtonDown(char id) {
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
        bool isButtonUp  (char id) { return !isButtonDown(id); }

    private:
        Eigen::Vector3f   _mousePos;
        unsigned int      _buttonCount;
        std::vector<char> _buttons;
    };
}

#endif // MOUSESTATE_H_