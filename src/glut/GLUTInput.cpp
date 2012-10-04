#include "GLUTInput.h"

namespace phantom {

    GLUTInput::GLUTInput() {
        glutKeyboardFunc        (GLUTInput::keyboardListener);
        glutKeyboardUpFunc      (GLUTInput::keyboardUpListener);
        glutSpecialFunc         (GLUTInput::keyboardSpecialListener);
        glutSpecialUpFunc       (GLUTInput::keyboardSpecialUpListener);
        glutMouseFunc           (GLUTInput::mouseListener);
        glutMotionFunc          (GLUTInput::mouseMotionListener);
        glutPassiveMotionFunc   (GLUTInput::mouseMotionListener);
    }

    void GLUTInput::getKeyboardState() {
        return;
    }

    void GLUTInput::getMouseState() {
        return;
    }


    void GLUTInput::keyboardListener(unsigned char keycode, int mouseX, int mouseY) {
        //InputState::getMe()->getKeyboardState()->handleEvent(keycode, 1);
    }

    void GLUTInput::keyboardUpListener(unsigned char keycode, int mouseX, int mouseY) {
        //InputState::getMe()->getKeyboardState()->handleEvent(keycode, 0);
    }

    void GLUTInput::keyboardSpecialListener(int code, int mouseX, int mouseY) {
        //InputState::getMe()->getKeyboardState()->handleEvent(static_cast<unsigned char> (code), 1);
    }

    void GLUTInput::keyboardSpecialUpListener(int code, int mouseX, int mouseY) {
        //InputState::getMe()->getKeyboardState()->handleEvent(static_cast<unsigned char> (code), 0);
    }

    void GLUTInput::mouseListener(int button, int state, int mouseX, int mouseY) {
        //InputState::getMe()->getMouseState()->handleEvent(button, 1 - state);
    }

    void GLUTInput::mouseMotionListener(int mouseX, int mouseY) {
        //InputState::getMe()->getMouseState()->handleEvent(Eigen::Vector3f(static_cast<float> (mouseX), static_cast<float> (mouseY), 1));
    }
}