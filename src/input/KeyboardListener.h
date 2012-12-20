#ifndef KEYBOARDLISTENER_H_
#define KEYBOARDLISTENER_H_

#include <thread>
#include <CompileConfig.h>

namespace phantom {
    class Composite;
    class Driver;
    class PhantomGame;
    class KeyboardState;

    class LIBEXPORT KeyboardListener {
    public:
        KeyboardListener(Driver *driver, PhantomGame *game);
        ~KeyboardListener();

        void update();
        static KeyboardState *lock(Composite* keycomp);
        static KeyboardState *unlock(Composite* keycomp);
        bool isLocked() { return _locked; }

    private:
        static KeyboardListener *INSTANCE;

        KeyboardListener(const KeyboardListener& copy) : _locked(false), _key(nullptr), _driver(nullptr), _game(nullptr), _thread(nullptr){ }
        KeyboardListener* operator=(const KeyboardListener& copy){ return 0; }

        bool _locked;
        Composite *_key;
        Driver *_driver;
        PhantomGame *_game;
        std::thread *_thread;
    };
}
#endif // !KEYBOARDLISTENER_H_
