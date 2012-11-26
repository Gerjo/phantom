#include "Time.h"

namespace phantom {
    PhantomTime::PhantomTime(float elapsed, float totalGameTime, double currentTime) {
        _elapsed = elapsed;
        _totalGameTime = totalGameTime;
        _currentTime = currentTime;
    }

    PhantomTime::~PhantomTime() {
    }

    float PhantomTime::getElapsed() const {
        return _elapsed;
    }

    float PhantomTime::getTotalGameTime() const {
        return _totalGameTime;
    }

    double PhantomTime::getTime() const {
        return _currentTime;
    }
}