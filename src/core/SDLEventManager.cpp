#include "SDLEventManager.h"

namespace phantom {
	void SDLEventManager::update(float elapsed)
	{
		EventManager::update(elapsed);

		SDL_Event ev;
		while(SDL_PollEvent(&ev))
		{
			// Send the event where ever it has to go.
			std::cout << "TODO: SDL Event Manager (btw just received key: " << ev.key.keysym.sym << ")\n"; 
		}
	}
}