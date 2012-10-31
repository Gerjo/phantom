#ifndef KEYBOARDSTATE_H_
#define KEYBOARDSTATE_H_

#include <CompileConfig.h>
#include <vector>

namespace phantom {
	class LIBEXPORT KeyboardState {
	public:
		KeyboardState();
		~KeyboardState();

		void handleEvent(char id, char newValue);

		bool isKeyDown(char id);
		bool isKeyUp(char id);

        std::vector<char>* changes();
        std::vector<char>* changesUp();

	private:
		char _keys[256];
        std::vector<char> _changedDown;
        std::vector<char> _changedUp;
	};
}

#endif // KEYBOARDSTATE_H_
