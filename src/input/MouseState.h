#ifndef MOUSESTATE_H_
#define MOUSESTATE_H_

#include <Eigen/Geometry>
#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT MouseState {
	public:
		MouseState() { };
		~MouseState() { };

		void handleEvent(Eigen::Vector3f newValue){ _mousePos = newValue;        }
		void handleEvent(char id, char newValue)  { _mouseButton[id] = newValue; }

		const Eigen::Vector3f& getMousePosition() { return _mousePos; }

		bool isButtonDown(char id) { return _mouseButton[id] == 1; }
		bool isButtonUp  (char id) { return !isButtonDown(id); }

	private:
		Eigen::Vector3f _mousePos;
		char _mouseButton[16];
	};
}

#endif // MOUSESTATE_H_