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

        /**
        * Handle mouse event when the position is changed.
        *
        * @param newValue The new position of the mouse.
        */
        void handleEvent(Vector3 newValue);

        /**
        * Hande mouse event when the button state is changed.
        *
        * @param id The identity of the button that has changed.
        * @param newValue The new value it should get.
        */
        void handleEvent(char id, char newValue);

        /**
        * Returns the current position of the mouse.
        *
        * @return Returns the current position of the mouse.
        */
        Vector3 getPosition();

        /**
        * Returns true if the button is down.
        *
        * @return Returns true if the button is down.
        * @param id The keycode of the button you want to check.
        */
        bool isButtonUp(unsigned char id);

        /**
        * Returns true if the button is up.
        *
        * @return Returns true if the button is up.
        * @param id The keycode of the button you want to check.
        */
        bool isButtonDown(unsigned char id);

    private:
        Vector3 _mousePos;
        unsigned int _buttonCount;
        std::vector<char> _buttons;
    };
}

#endif // MOUSESTATE_H_