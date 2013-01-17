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
        /**
        * Read a file into a buffer.
        *
        * @param filelocation The location of the file relative to the working directory.
        * @param filecontent A pointer to the buffer where the content of the file should be written to.
        * @param lenght A pointer to the buffer where the lenght of the file should be written to.
        */
        static void     readfile(const char *filelocation, char **filecontent, unsigned int *length);
        
        /**
        * Returns the time since epoch.
        *
        * @return Returns the time since epoch.
        */
        static double   getTime();
    };
}
#endif