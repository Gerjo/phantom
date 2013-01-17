#ifndef PHANTOMEXCEPTION_H
#define PHANTOMEXCEPTION_H

#include <CompileConfig.h>
#include <string>
#include <exception>

using namespace std;

namespace phantom{
    class LIBEXPORT PhantomException: public exception {
    public:
        PhantomException(const string error);

        /**
        * Should return more information of what exactly went wrong.
        *
        * @return More information of what went wrong.
        */
        const char* what() const throw();

        virtual ~PhantomException() throw() {}

    private:
        string _error;
    };
} /* namespace phantom */

#endif /* PHANTOMEXCEPTION_H */