#ifndef UTIL_H
#define UTIL_H

#ifndef WIN32
#define C11AVAILABLE
#endif

#ifdef C11AVAILABLE
#   include <chrono>
#endif

#include <CompileConfig.h>

#ifdef WIN32
#   include <Windows.h>

#else
#   include <sys/time.h>
#   include <unistd.h>
#endif

namespace phantom{
    class LIBEXPORT Util{
    public:
        static void     readfile(const char *filename, char **filecontent, unsigned int *length);
        static double   getTime();

    };
}
#endif