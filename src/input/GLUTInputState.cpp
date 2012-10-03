#include "GLUTInputState.h"
#include <iostream>

namespace phantom {

    void GLUTInputState::setup() {
        std::cout << "Initializing GLUT InputState handler..." << std::endl;

        glutKeyboardFunc(phantom::GLUTInputState::keyboardListener);
        glutKeyboardUpFunc(phantom::GLUTInputState::keyboardUpListener);
        glutSpecialFunc(phantom::GLUTInputState::keyboardSpecialListener);
        glutSpecialUpFunc(phantom::GLUTInputState::keyboardSpecialUpListener);
        glutMouseFunc(phantom::GLUTInputState::mouseListener);
        glutMotionFunc(phantom::GLUTInputState::mouseMotionListener);
        glutPassiveMotionFunc(phantom::GLUTInputState::mouseMotionListener);
    }

    void GLUTInputState::keyboardListener(unsigned char keycode, int mouseX, int mouseY) {
        InputState::getMe()->getKeyboardState()->handleEvent(keycode, 1);
    }

    void GLUTInputState::keyboardUpListener(unsigned char keycode, int mouseX, int mouseY) {
        InputState::getMe()->getKeyboardState()->handleEvent(keycode, 0);
    }

    void GLUTInputState::keyboardSpecialListener(int code, int mouseX, int mouseY) {
        InputState::getMe()->getKeyboardState()->handleEvent(static_cast<unsigned char> (code), 1);
    }

    void GLUTInputState::keyboardSpecialUpListener(int code, int mouseX, int mouseY) {
        InputState::getMe()->getKeyboardState()->handleEvent(static_cast<unsigned char> (code), 0);
    }

    void GLUTInputState::mouseListener(int button, int state, int mouseX, int mouseY) {
        InputState::getMe()->getMouseState()->handleEvent(button, 1 - state);
        cout << "mouse is doing something" << endl;
    }

    void GLUTInputState::mouseMotionListener(int mouseX, int mouseY) {
        cout << "mouse is in motion!" << endl;
        InputState::getMe()->getMouseState()->handleEvent(Eigen::Vector3f(static_cast<float> (mouseX), static_cast<float> (mouseY), 1));
    }
}
