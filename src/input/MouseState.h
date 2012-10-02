#ifndef MOUSESTATE_H_
#define MOUSESTATE_H_

#include <Eigen/Geometry>
#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT MouseState {
	public:
		MouseState() { };
		~MouseState() { };

		void handleEvent(Eigen::Vector2f newValue){ _mousePos = newValue;        }
		void handleEvent(char id, char newValue)  { _mouseButton[id] = newValue; }

		const Eigen::Vector2f& getMousePosition() { return _mousePos; }

		bool isButtonDown(char id) { if(_mouseButton[id] == 1) return true; else return false; }
		bool isButtonUp  (char id) { if(_mouseButton[id] == 0) return true; else return false; }

	private:
		Eigen::Vector2f _mousePos;
		char _mouseButton[16];
	};
}

#endif // MOUSESTATE_H_