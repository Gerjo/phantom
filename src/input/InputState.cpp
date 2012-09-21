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
	
	void InputState::setMe(InputState *me) {
		if(_instance == 0)
			_instance = me;
		else {
			std::cout << "Input is already set. Do not call me twice.\n";
		}
	}

	void InputState::onAdd(Composite *parent) {
		InputState::setMe(this);
		this->setup();
	}
}

