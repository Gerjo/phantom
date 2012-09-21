#ifndef KEYBOARDSTATE_H_
#define KEYBOARDSTATE_H_

#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT KeyboardState {
	public:
		KeyboardState() { };
		~KeyboardState() { };

		void handleEvent(char id, char newValue) { _keys[id] = newValue; }

		bool isKeyDown(char id) { if(_keys[id] == 1) return true; else return false; }
		bool isKeyUp  (char id) { if(_keys[id] == 0) return true; else return false; }

	private:
		char _keys[256];
	};
}

#endif // KEYBOARDSTATE_H_
