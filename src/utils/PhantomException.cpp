#include "PhantomException.h"

namespace phantom{
    PhantomException::PhantomException(string error = "something went wrong :O!"):exception(error.c_str()),_error(error){

    }
    const char* PhantomException::what(){
        return _error.c_str();
    }
}/* namespace phantom */