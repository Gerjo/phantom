#ifndef INPUT_H
#define	INPUT_H

namespace phantom {

    class Input {
    public:

        virtual void getKeyboardState() = 0;
        virtual void getMouseState() = 0;

        // *hint* *hint*
        // virtual void getWiiMoteState(const int index);
        // virtual void getXboxState(const int index);
    };

}

#endif	/* INPUT_H */

