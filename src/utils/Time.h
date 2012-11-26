#ifndef TIME_HA_
#define TIME_HA_

#include <CompileConfig.h>

namespace phantom {
    class LIBEXPORT PhantomTime {
    public:
        PhantomTime(float elapsed, float totalGameTime, double currentTime);
        ~PhantomTime();

        float getElapsed() const;
        float getTotalGameTime() const;
        double getTime() const;

    private:
        float _elapsed;
        float _totalGameTime;
        double _currentTime;
    };
}

#endif