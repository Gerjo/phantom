#ifndef TIME_HA_
#define TIME_HA_

#include <CompileConfig.h>

namespace phantom {
    class LIBEXPORT Time {
    public:
        Time(float elapsed, float totalGameTime, double currentTime);
        ~Time();

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