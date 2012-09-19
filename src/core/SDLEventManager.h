#ifndef SDLEVENTMANAGER_H_
#define SDLEVENTMANAGER_H_

#include <core/EventManager.h>
#include <vector>
#include <SDL/SDL.h>

namespace phantom {
	class SDLEventManager : public EventManager {
	public:
		virtual void update(float elapsed);
	};
}

#endif // SDLEVENTMANAGER_H_