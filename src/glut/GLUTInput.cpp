#include "GLUTInput.h"

namespace phantom {

    GLUTInput* GLUTInput::INSTANCE = 0;

    GLUTInput::GLUTInput(PhantomGame *game) : Input(game) {
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
        Vector3 mouseTranslated(mouseX, mouseY, 0);
        printf("Mouseposition before: x: %f, y: %f, z: %f\n", mouseTranslated.x, mouseTranslated.y, mouseTranslated.z);
        Vector3 translation = (GLUTInput::INSTANCE->_game->getViewPort() / GLUTInput::INSTANCE->_game->getWorldSize());
        printf("Mouseposition trnaslation: x: %f, y: %f, z: %f\n", translation.x, translation.y, translation.z);
        mouseTranslated = mouseTranslated / translation;
        mouseTranslated.z = 0;
        printf("Mouseposition after: x: %f, y: %f, z: %f\n", mouseTranslated.x, mouseTranslated.y, mouseTranslated.z);
        GLUTInput::INSTANCE->_mouseState->handleEvent(mouseTranslated);
    }
}