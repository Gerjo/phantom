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
        Input(PhantomGame *game) : _game(game), _keyboardState(nullptr), _mouseState(nullptr) { }
        virtual ~Input() {}

        /**
        * Retrieve the current KeyboardState.
        *
        * @return Returns the current keyboard state.
        */
        virtual KeyboardState* getKeyboardState() { return _keyboardState; }
        
        /**
        * Retrieve the current MouseState.
        *
        * @return Returns the current MouseState.
        */
        virtual MouseState* getMouseState() { return _mouseState; }

    protected:
        PhantomGame *_game;
        KeyboardState *_keyboardState;
        MouseState *_mouseState;
    private:
        Input(const Input& input) : _game(nullptr), _keyboardState(nullptr), _mouseState(nullptr) {}
    };
}

#endif	/* INPUT_H */

