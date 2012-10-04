#ifndef INPUTSTATE_H_
#define INPUTSTATE_H_

#include <input/KeyboardState.h>
#include <input/MouseState.h>
#include <iostream>
#include <CompileConfig.h>

namespace phantom {
    namespace Buttons {
        static unsigned char LEFT_MOUSE = 0;
        static unsigned char MIDDLE_MOUSE = 1;
        static unsigned char RIGHT_MOUSE = 2;
    }

	class LIBEXPORT InputState : public Composite {
	public:
        InputState() { }

		static void setMe(InputState *me);
		static InputState *getMe();

		virtual void setup() = 0;

		virtual void handleEvent(void *e) = 0;
		virtual void onAdd(Composite *parent);

		KeyboardState *getKeyboardState() { return &_keyboardState; }
		MouseState    *getMouseState()    { return &_mouseState;    }

	private:
		KeyboardState		        _keyboardState;
		MouseState			        _mouseState;
		static InputState	        *_instance;
	};
}

#endif // INPUTSTATE_H_