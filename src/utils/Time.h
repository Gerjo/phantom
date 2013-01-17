#ifndef TIME_HA_
#define TIME_HA_

#include <CompileConfig.h>

namespace phantom {
    class LIBEXPORT PhantomTime {
    public:
        PhantomTime(float elapsed, float totalGameTime, double currentTime);
        ~PhantomTime();
        
        /**
        * Returns the elapsed time since last update call.
        *
        * @return Returns the elapsed time since last update call.
        */
        float getElapsed() const;
        
        /**
        * Returns the total time the game is active.
        *
        * @return Returns the total time the game is active.
        */
        float getTotalGameTime() const;

        /**
        * Returns the time since epoch.
        *
        * @return Returns the time since epoch.
        */
        double getTime() const;

    private:
        float _elapsed;
        float _totalGameTime;
        double _currentTime;
    };
}

#endif