#include "pch.h"
#include "Sounds.h"

#include <utils/PhantomException.h>

namespace phantom {
    Sounds::Sounds(void) {
    }

    Sounds::~Sounds(void) {
    }

    int Sounds::playSounds(const string &filename) {
        if(!isCached(filename)) {
            insertIntoCache(filename);
        }

        return 0;
    }

    bool Sounds::stopSounds(int id) {
        return false;
    }

    bool Sounds::isCached(const string &filename) {
        return false;
    }

    void Sounds::insertIntoCache(const string &filename) {
        if(filename.find(".ogg") == string::npos) {
            throw PhantomException("Container in " + filename + " is not supported.");
        }


    }
}
