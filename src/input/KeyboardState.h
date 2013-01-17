#ifndef KEYBOARDSTATE_H_
#define KEYBOARDSTATE_H_

#include <CompileConfig.h>
#include <vector>

namespace phantom {
	class LIBEXPORT KeyboardState {
	public:
		KeyboardState();
		~KeyboardState();

        /**
        * Handles an keyboard event.
        *
        * @param id The character id.
        * @param newValue The new value associated with the key.
        */
		void handleEvent(char id, char newValue);

        /**
        * Returns the character buffer.
        *
        * @return Returns the character buffer.
        */
        unsigned char *getBuffer();

        /**
        * Returns true if the key is down.
        *
        * @return Returns true if the key is down.
        * @param id The keycode of the button you want to check.
        */
		bool isKeyDown(char id);

		/**
        * Returns true if the key is up.
        *
        * @return Returns true if the key is up.
        * @param id The keycode of the button you want to check.
        */
        bool isKeyUp(char id);

        /**
        * Returns all changes since the last update run.
        *
        * @return Returns all the changes since the last update run.
        */
        std::vector<char>* changes();

        /**
        * Returns all key release changes since the last update run.
        *
        * @return Returns all key release changes since the last update run.
        */
        std::vector<char>* changesUp();

	private:
		unsigned char _keys[256];
        std::vector<char> _changedDown;
        std::vector<char> _changedUp;
	};
}

#endif // KEYBOARDSTATE_H_
