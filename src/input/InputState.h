#ifndef INPUTSTATE_H_
#define INPUTSTATE_H_

#include <input/KeyboardState.h>
#include <input/MouseState.h>

namespace phantom {
	class InputState {
	public:
		InputState () { }
		~InputState() { }

		virtual void handleEvent(void *e) { }

		KeyboardState *getKeyboardState() { return &_keyboardState; }
		MouseState    *getMouseState()    { return &_mouseState;    }

	private:
		KeyboardState _keyboardState;
		MouseState    _mouseState;
	};
}

#endif // INPUTSTATE_H_