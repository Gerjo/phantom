#include "EventManager.h"

namespace phantom {
	void EventManager::addEvent(Event *e)
	{
		this->_eventList.push_back(e);
	}
	
	void EventManager::update(float elapsed)
	{	
		Composite::update(elapsed);

		while(_eventList.size() > 0)
		{
			Event *e = _eventList.back();
			_eventList.pop_back();
			delete e;
		}
	}
}