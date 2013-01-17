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
        
        /**
        * Locks the keyboard to a certain composite.
        *
        * @return Returns the current keyboard state.
        * @param keycomp The component that owns the listener.
        */
        static KeyboardState *lock(Composite* keycomp);
        
        /**
        * Unlocks the keyboard to other composites.
        *
        * @param keycom The component that owns the listener.
        */
        static void unlock(Composite* keycomp);

        /**
        * Returns if the listener is locked.
        *
        * @return Returns true if the listener is locked.
        */
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
