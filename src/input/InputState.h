#ifndef INPUTSTATE_H_
#define INPUTSTATE_H_

#include <input/KeyboardState.h>
#include <input/MouseState.h>
#include <core/EventManager.h>
#include <iostream>

namespace phantom {
	class InputState : public Composite {
	public:
		static void createMe(InputState *me);
		static InputState *getMe();

		virtual void setup() = 0;

		virtual void handleEvent(void *e) = 0;
		virtual void onAdd(Composite *parent);

		KeyboardState *getKeyboardState() { return &_keyboardState; }
		MouseState    *getMouseState()    { return &_mouseState;    }

	private:
		KeyboardState		_keyboardState;
		MouseState			_mouseState;
		static InputState	*_instance;
	};
}

#endif // INPUTSTATE_H_