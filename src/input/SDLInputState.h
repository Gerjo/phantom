#ifndef SDLINPUTSTATE_H_
#define SDLINPUTSTATE_H_

#include <input/InputState.h>

namespace phantom {
	class SDLInputState : public InputState {
	public:
		SDLInputState() : InputState() { }
		~SDLInputState() { }

		virtual void handleEvent(Event *e);
	};
}

#endif // SDLINPUTSTATE_H_