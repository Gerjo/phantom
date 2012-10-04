#ifndef INPUT_H
#define	INPUT_H

#include <input/KeyboardState.h>
#include <input/MouseState.h>

#include <iostream>

using namespace std;

namespace phantom {

    class Input {
    public:
        Input() {}
        virtual KeyboardState* getKeyboardState() = 0;
        virtual MouseState* getMouseState() = 0;

        // *hint* *hint*
        // virtual void getWiiMoteState(const int index);
        // virtual void getXboxState(const int index);

    private:
        Input(const Input& input) {}

    };
}

#endif	/* INPUT_H */

