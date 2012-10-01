#ifndef PHANTOMEXCEPTION_H
#define PHANTOMEXCEPTION_H

#include <CompileConfig.h>
#include <string>
#include <exception>

using namespace std;

namespace phantom{
    class LIBEXPORT PhantomException: public exception {
    public:
        PhantomException(const string error) {
            _error = error;
        }

        const char* what() const throw(...) {
            return _error.c_str();
        }

        virtual ~PhantomException() throw(...) {
            
        }

    private:
        string _error;
    };
} /* namespace phantom */

#endif /* PHANTOMEXCEPTION_H */