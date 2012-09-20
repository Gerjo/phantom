#ifndef INPUTSTATE_H_
#define INPUTSTATE_H_

#include <input/KeyboardState.h>
#include <input/MouseState.h>
#include <core/EventManager.h>
#include <iostream>

namespace phantom {
	class InputState {
	public:
		static InputState *getMe() {
			if(_instance != 0)
				return _instance;
			else {
				std::cout << "Please call createMe first with an valid InputState handler.\n";
				return 0;
			}
		}

		static void createMe(InputState *me) {
			if(_instance == 0)
				_instance = me;
			else {
				std::cout << "Input is already created. Do not call me twice.\n";
			}
		}

		virtual void setup() = 0;

		virtual void handleEvent(void *e) = 0;

		KeyboardState *getKeyboardState() { return &_keyboardState; }
		MouseState    *getMouseState()    { return &_mouseState;    }

	private:
		KeyboardState		_keyboardState;
		MouseState			_mouseState;
		static InputState	*_instance;
	};
}

#endif // INPUTSTATE_H_