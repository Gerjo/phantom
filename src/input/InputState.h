#ifndef INPUTSTATE_H_
#define INPUTSTATE_H_

#include <input/KeyboardState.h>
#include <input/MouseState.h>
#include <core/EventManager.h>
#include <iostream>
#include <CompileConfig.h>

namespace phantom {
    namespace Buttons {
        enum BUTTONS {
            LEFT_MOUSE,
            MIDDLE_MOUSE,
            RIGHT_MOUSE,
            // Must remain bottom.
            SIZEOF
        };
    }

	class LIBEXPORT InputState : public Composite {
	public:
        InputState() {
            for(unsigned int i = 0; i < Buttons::SIZEOF; ++i)
                _inputMap.push_back(char());
        }

		static void setMe(InputState *me);
		static InputState *getMe();

		virtual void setup() = 0;

		virtual void handleEvent(void *e) = 0;
		virtual void onAdd(Composite *parent);

        std::vector<unsigned char> getMap(Buttons::BUTTONS id) { return _inputMap; } 

		KeyboardState *getKeyboardState() { return &_keyboardState; }
		MouseState    *getMouseState()    { return &_mouseState;    }

    protected:
        std::vector<unsigned char>  _inputMap;

	private:
		KeyboardState		        _keyboardState;
		MouseState			        _mouseState;
		static InputState	        *_instance;
	};
}

#endif // INPUTSTATE_H_