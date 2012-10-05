#include "GLUTInput.h"

namespace phantom {

    GLUTInput* GLUTInput::INSTANCE = 0;

    GLUTInput::GLUTInput() {
        GLUTInput::INSTANCE = this;

        glutKeyboardFunc        (GLUTInput::keyboardListener);
        glutKeyboardUpFunc      (GLUTInput::keyboardUpListener);
        glutSpecialFunc         (GLUTInput::keyboardSpecialListener);
        glutSpecialUpFunc       (GLUTInput::keyboardSpecialUpListener);
        glutMouseFunc           (GLUTInput::mouseListener);
        glutMotionFunc          (GLUTInput::mouseMotionListener);
        glutPassiveMotionFunc   (GLUTInput::mouseMotionListener);

        _keyboardState = new KeyboardState();
        _mouseState    = new MouseState();
    }

    KeyboardState* GLUTInput::getKeyboardState() {
        return _keyboardState;
    }

    MouseState* GLUTInput::getMouseState() {
        return _mouseState;
    }

    void GLUTInput::keyboardListener(unsigned char keycode, int mouseX, int mouseY) {
        GLUTInput::INSTANCE->_keyboardState->handleEvent(keycode, 1);
    }

    void GLUTInput::keyboardUpListener(unsigned char keycode, int mouseX, int mouseY) {
        GLUTInput::INSTANCE->_keyboardState->handleEvent(keycode, 0);
    }

    void GLUTInput::keyboardSpecialListener(int code, int mouseX, int mouseY) {
        GLUTInput::INSTANCE->_keyboardState->handleEvent(static_cast<unsigned char> (code), 1);
    }

    void GLUTInput::keyboardSpecialUpListener(int code, int mouseX, int mouseY) {
        GLUTInput::INSTANCE->_keyboardState->handleEvent(static_cast<unsigned char> (code), 0);
    }

    void GLUTInput::mouseListener(int button, int state, int mouseX, int mouseY) {
        GLUTInput::INSTANCE->_mouseState->handleEvent(button, 1 - state);
    }

    void GLUTInput::mouseMotionListener(int mouseX, int mouseY) {
        GLUTInput::INSTANCE->_mouseState->handleEvent(Vector3(static_cast<float> (mouseX), static_cast<float> (mouseY), 1));
    }
}