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
	void static phantom_sleep(float timems){
			#ifndef WIN32
				usleep(timems*1000 );
			#else
				Sleep(timems);
			#endif
	}
};
}
#endif