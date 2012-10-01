#include "PhantomException.h"
#include <iostream>

namespace phantom{
    PhantomException::PhantomException(const string error):_error(error){
        std::cout << error << std::endl;
    }
    const char* PhantomException::what() const throw() {
        return _error.c_str();
    }
}/* namespace phantom */