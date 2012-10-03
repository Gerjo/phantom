#ifndef MOUSESTATE_H_
#define MOUSESTATE_H_

#include <Eigen/Geometry>
#include <CompileConfig.h>
#include <deque>
#include <iostream>

#include <GL/freeglut.h>
#include <vector>

namespace phantom {
	class LIBEXPORT MouseState {
	public:
		MouseState() { for(unsigned int i = 0; i < 10; ++i) _buttons.push_back('0'); };
		~MouseState() { };

		void handleEvent(Eigen::Vector3f newValue){ _mousePos = newValue;    }
		void handleEvent(char id, char newValue)  { _buttons[id] = newValue; }

		const Eigen::Vector3f& getMousePosition() { return _mousePos; }

        bool isButtonDown(char id) { return _buttons.at(id) == 1; }
		bool isButtonUp  (char id) { return !isButtonDown(id); }

        // TODO: remove glut stuff:
        static const int BUTTON_LEFT   = GLUT_LEFT_BUTTON;
        static const int BUTTON_MIDDLE = GLUT_MIDDLE_BUTTON;
        static const int BUTTON_RIGHT  = GLUT_RIGHT_BUTTON;
	private:
		Eigen::Vector3f   _mousePos;
        std::vector<char> _buttons;
	};
}

#endif // MOUSESTATE_H_