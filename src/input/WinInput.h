#ifndef WININPUT_H_
#define WININPUT_H_

#ifdef _WIN32

#include <input/Input.h>
#include <Windows.h>

class PhantomGame;

namespace phantom {
    class LIBEXPORT WinInput : public Input {
    public:
        WinInput(PhantomGame *game);

        void checkForChanges();
    };
}

#endif
#endif