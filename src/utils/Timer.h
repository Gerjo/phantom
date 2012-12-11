#ifndef TIMER_H
#define	TIMER_H

#include <CompileConfig.h>
#include <utils/Timer.h>
#include <utils/util.h>

namespace phantom {

    class LIBEXPORT Timer {
    public:

        Timer(double delay) : _delay(delay), _startTime(phantom::Util::getTime()), _isStopped(false) {

        }

        // Slightly more efficient overload. The update loop of your game
        // supplies a Time object.
        bool hasExpired(const PhantomTime& time) {
            if(_isStopped) {
                return false;
            }

            if (time.getTime() - _startTime > _delay) {
                return true;
            }

            return false;
        }

        bool hasExpired() {

            if(_isStopped) {
                return false;
            }

            double now = phantom::Util::getTime();

            if (now - _startTime > _delay) {
                return true;
            }

            return false;
        }

        Timer& stop() {
            _isStopped = true;

            return *this;
        }

        Timer& restart() {
            _isStopped = false;
            _startTime = phantom::Util::getTime();
            return *this;
        }

        Timer& setDelay(double delay) {
            _delay = delay;
            return *this;
        }

        bool isStopped() {
            return _isStopped;
        }

        bool expire(void) {
            _startTime = -1;
        }

    private:
        double _startTime;
        double _delay;
        bool _isStopped;
    };
}
#endif	/* TIMER_H */

