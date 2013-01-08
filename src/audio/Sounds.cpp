#include "pch.h"
#include "Sounds.h"
#include <audio/SoundData.h>
#include <audio/SoundLoader.h>
#include <core/Driver.h>
#include <utils/PhantomException.h>

namespace phantom {
    Sounds::Sounds(void) {
    }

    Sounds::~Sounds(void) {
        for(auto sound = _soundMap.begin(); sound != _soundMap.end(); ) {
            delete sound->second;
            sound->second = nullptr;
        }
        _soundMap.clear();
    }

    int Sounds::playSounds(const string &filename) {
        if(!isCached(filename)) {
            insertIntoCache(filename);
        }

        getDriver()->getAudioEngine()->playSound(_soundMap.at(filename));

        return 0;
    }

    bool Sounds::stopSounds(int id) {
        throw PhantomException("The lazy bastard hasn't implemented this OH NOOOES");
    }

    bool Sounds::isCached(const string &filename) {
        if(_soundMap.find(filename) != _soundMap.end())
            return true;
        return false;
    }

    void Sounds::insertIntoCache(const string &filename) {
        if(filename.find(".ogg") == string::npos) {
            throw PhantomException("Container in " + filename + " is not supported.");
        }

        SoundData *data = new SoundData();
        SoundLoader::loadVorbis(filename.c_str(), data);

        _soundMap.insert(pair<const string, SoundData*>(filename, data));

        getDriver()->getAudioEngine()->createSound(data);
    }
}
