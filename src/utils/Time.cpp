#include "Time.h"

namespace phantom {
    Time::Time(float elapsed, float totalGameTime, float currentTime) {
        _elapsed = elapsed;
        _totalGameTime = totalGameTime;
        _currentTime = currentTime;
    }

    Time::~Time() { 
    }

    float Time::getElapsed() const {
        return _elapsed;
    }

    float Time::getTotalGameTime() const {
        return _totalGameTime;
    }

    float Time::getTime() const {
        return _currentTime;
    }
}