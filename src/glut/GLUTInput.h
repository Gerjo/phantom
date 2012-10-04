#ifndef GLUTINPUT_H
#define	GLUTINPUT_H

#include <input/Input.h>

namespace phantom {
    class GLUTInput : public Input {
    public:
        GLUTInput();

        virtual void getKeyboardState();
        virtual void getMouseState();

    private:

    };
}

#endif	/* GLUTINPUT_H */

