#ifndef INPUT_H
#define	INPUT_H

#include <input/KeyboardState.h>
#include <input/MouseState.h>
#include <core/PhantomGame.h>
#include <iostream>

using namespace std;

namespace phantom {
    class LIBEXPORT Input {
    public:
        Input(PhantomGame *game) { _game = game; }
        virtual ~Input() {}
        virtual KeyboardState* getKeyboardState() { return _keyboardState; }
        virtual MouseState* getMouseState() { return _mouseState; }

        // *hint* *hint*
        // virtual void getWiiMoteState(const int index);
        // virtual void getXboxState(const int index);
        
    protected:
        PhantomGame *_game;
        KeyboardState *_keyboardState;
        MouseState *_mouseState;
    private:
        Input(const Input& input) {}
    };
}

#endif	/* INPUT_H */

