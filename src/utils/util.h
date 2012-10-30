#ifndef UTIL_H
#define UTIL_H

#define C11AVAILABLE

#ifndef C11AVAILABLE
#ifdef WIN32
	#include <Windows.h>
#else
    #include <sys/time.h>
    #include <unistd.h>
#endif
#else
    #include <chrono>
#endif

namespace phantom{
    class Util{
    public:
        double static getTime() {
            double total;
            #ifndef C11AVAILABLE
                #ifndef WIN32
                    timeval tv;
                    gettimeofday(&tv, NULL);

                    total = tv.tv_sec;
                    total += tv.tv_usec / 1000000.0;
                #else
                    SYSTEMTIME *lpSystemTime = new SYSTEMTIME();
                    GetLocalTime(lpSystemTime);

                    total = lpSystemTime->wSecond;
                    total += lpSystemTime->wMinute * 60;
                    total += lpSystemTime->wHour * 3600;
                    total += lpSystemTime->wDay * 86400;
                    total += lpSystemTime->wMilliseconds / 1000.0;

                    delete lpSystemTime;
                #endif
            #else
                total = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000000.0;
            #endif

            return total;
        }
    };
}
#endif