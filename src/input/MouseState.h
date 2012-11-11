#ifndef MOUSESTATE_H_
#define MOUSESTATE_H_

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
        MouseState();
        ~MouseState();

        void handleEvent(Vector3 newValue);
        void handleEvent(char id, char newValue);

        Vector3 getPosition();
        bool isButtonUp(unsigned char id);
        bool isButtonDown(unsigned char id);

    private:
        Vector3 _mousePos;
        unsigned int _buttonCount;
        std::vector<char> _buttons;
    };
}

#endif // MOUSESTATE_H_