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
};
}
#endif