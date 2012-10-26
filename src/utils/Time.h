#ifndef TIME_HA_
#define TIME_HA_

#include <CompileConfig.h>

namespace phantom {
    class LIBEXPORT Time {
    public:
        Time(float elapsed, float totalGameTime, float currentTime);
        ~Time();
        
        float getElapsed() const;
        float getTotalGameTime() const;
        float getTime() const;
    
    private:
        float _elapsed;
        float _totalGameTime;
        float _currentTime;
    };
}

#endif