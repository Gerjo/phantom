#include "InputState.h"

namespace phantom {

	InputState *InputState::_instance = 0;

	InputState *InputState::getMe() {
		if(_instance != 0)
			return _instance;
		else {
			std::cout << "Please call createMe first with an valid InputState handler.\n";
			return 0;
		}
	}
	
	void InputState::createMe(InputState *me) {
		if(_instance == 0)
			_instance = me;
		else {
			std::cout << "Input is already created. Do not call me twice.\n";
		}
	}

	void InputState::onAdd(Composite *parent) {
		this->setup();
	}
}

