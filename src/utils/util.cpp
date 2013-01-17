#include <pch.h>
#include <phantom.h>
#include "util.h"

namespace phantom {


    void Util::readfile(const char *filelocation, char **filecontent, unsigned int *length) {
        FILE *fp;
        size_t size = 0;
        char *content;

        if (filelocation != NULL) {
#ifdef WIN32
            fopen_s(&fp, filelocation, "rt");
#else
            fp = fopen(filelocation,"rt");
#endif
            if (fp != NULL) {
                fseek(fp, 0, SEEK_END);
                size = ftell(fp);
                rewind(fp);

                if (size > 0) {
                    content = new char[size + 1];
                    size = fread(content, sizeof(char), size, fp);
                    content[size] = '\0';
                }
                fclose(fp);
            }
        }
        *length = static_cast<unsigned int>(size);
        *filecontent = content;
    }

    double Util::getTime() {
#ifndef C11AVAILABLE
#ifndef WIN32
        double total;

        timeval tv;
        gettimeofday(&tv, NULL);

        total = tv.tv_sec;
        total += tv.tv_usec / 1000000.0;

        return total;
#else
        return timeGetTime() * 0.001;

        /*SYSTEMTIME *lpSystemTime = new SYSTEMTIME();
        GetLocalTime(lpSystemTime);

        total = lpSystemTime->wSecond;
        total += lpSystemTime->wMinute * 60;
        total += lpSystemTime->wHour * 3600;
        total += lpSystemTime->wDay * 86400;
        total += lpSystemTime->wMilliseconds / 1000.0;

        delete lpSystemTime;*/
#endif
#else
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000000.0;
#endif
    }
}