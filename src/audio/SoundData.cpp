#include "pch.h"
#include "SoundData.h"

namespace phantom {
    SoundData::SoundData() : state(0), bufferID(0), sourceID(0), format(0), freq(0), channels(0), bitsPerSample(0), bufferData(nullptr) {
        bufferData = new std::vector<char>();
    }

    SoundData::~SoundData() {
        delete bufferData;
    }
}
