#ifndef NULLDRIVER_H_
#define NULLDRIVER_H_
#include <core/Driver.h>

namespace phantom {
    // As the name assumes, the null driver will do as less as possible. Use this driver for servers and such.
    class NullDriver : public Driver {
    public:
        NullDriver(PhantomGame *game) : Driver(game) { }

        void onUpdate(PhantomTime time) { }
        void onRender() { }

        Camera* createCamera() { return new Camera(0); }
    };
}

#endif
