#include "GLUTInputState.h"

namespace phantom {
	void GLUTInputState::setup() {
		glutKeyboardFunc(phantom::GLUTInputState::keyboardListener);
		glutKeyboardUpFunc(phantom::GLUTInputState::keyboardUpListener);
		glutSpecialFunc(phantom::GLUTInputState::keyboardSpecialListener);
		glutSpecialUpFunc(phantom::GLUTInputState::keyboardSpecialUpListener);
		glutMouseFunc(phantom::GLUTInputState::mouseListener);
		glutMotionFunc(phantom::GLUTInputState::mouseMotionListener);
	}

	void __cdecl GLUTInputState::keyboardListener(unsigned char keycode, int mouseX, int mouseY) {
		InputState::getMe()->getKeyboardState()->handleEvent(keycode, 1);
	}

	void __cdecl GLUTInputState::keyboardUpListener(unsigned char keycode, int mouseX, int mouseY) {
		InputState::getMe()->getKeyboardState()->handleEvent(keycode, 0);
	}

	void __cdecl GLUTInputState::keyboardSpecialListener(int code, int mouseX, int mouseY) {
		InputState::getMe()->getKeyboardState()->handleEvent(static_cast<unsigned char>(code), 1);
	}
	
	void __cdecl GLUTInputState::keyboardSpecialUpListener(int code, int mouseX, int mouseY) {
		InputState::getMe()->getKeyboardState()->handleEvent(static_cast<unsigned char>(code), 0);
	}

	void __cdecl GLUTInputState::mouseListener(int button, int state, int mouseX, int mouseY) {
		InputState::getMe()->getMouseState()->handleEvent(button, 0);
	}

	void __cdecl GLUTInputState::mouseMotionListener(int mouseX, int mouseY) {
		InputState::getMe()->getMouseState()->handleEvent(Eigen::Vector2f(static_cast<float>(mouseX), static_cast<float>(mouseY)));
	}
}