#ifndef UTIL_H
#define UTIL_H

#ifdef WIN32
	#include <Windows.h>
#else
    #include <sys/time.h>
    #include <unistd.h>
#endif

namespace phantom{
    class Util{
    public:
        void static sleep(float timems){
            #ifndef WIN32
                usleep(timems * 1000);
            #else
                Sleep(static_cast<DWORD>(timems));
            #endif
        }

        double static getTime() {
            #ifndef WIN32
                timeval tv;
                gettimeofday(&tv, NULL);

                double total = tv.tv_sec;
                total += tv.tv_usec / 1000000.0;
            #else
                SYSTEMTIME *lpSystemTime = new SYSTEMTIME();
                GetLocalTime(lpSystemTime);

                double total = lpSystemTime->wSecond;
                total += lpSystemTime->wMinute * 60;
                total += lpSystemTime->wHour * 3600;
                total += lpSystemTime->wDay * 86400;
                total += lpSystemTime->wMilliseconds / 1000.0;

                delete lpSystemTime;
            #endif

            return total;
        }
    };
}
#endif