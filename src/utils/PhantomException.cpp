#include <pch.h>
#include "PhantomException.h"

namespace phantom{
    PhantomException::PhantomException(const string error):_error(error) {
#ifdef WIN32
        std::cout << error << std::endl;
#endif
    }
    const char* PhantomException::what() const throw() {
        return _error.c_str();
    }
}/* namespace phantom */