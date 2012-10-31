#ifndef KEYBOARDSTATE_H_
#define KEYBOARDSTATE_H_

#include <CompileConfig.h>

namespace phantom {
	class LIBEXPORT KeyboardState {
	public:
		KeyboardState();
		~KeyboardState();

		void handleEvent(char id, char newValue);

		bool isKeyDown(char id);
		bool isKeyUp(char id);

	private:
		char _keys[256];
	};
}

#endif // KEYBOARDSTATE_H_
