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
        virtual KeyboardState* getKeyboardState() = 0;
        virtual MouseState* getMouseState() = 0;

        // *hint* *hint*
        // virtual void getWiiMoteState(const int index);
        // virtual void getXboxState(const int index);
        
    protected:
        PhantomGame *_game;
    private:
        Input(const Input& input) {}
    };
}

#endif	/* INPUT_H */

