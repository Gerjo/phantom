#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include <core/Composite.h>
#include <phantom.h>

namespace phantom {

	typedef struct Event {
		void *payload;
		char *type;
	} Event;

	class EventManager : public Composite {
	public:
		void addEvent(Event *e);
		virtual void update(float elapsed);
	private:
		std::vector<Event *> _eventList;
	};
}

#endif // EVENTMANAGER_H_