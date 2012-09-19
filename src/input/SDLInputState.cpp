#include "SDLInputState.h"

namespace phantom {
	void SDLInputState::handleEvent(Event *e)
	{
		if(e->type == "SDL_InputEvent")
		{
			// Do some awesome stuff.
		}
	}
}