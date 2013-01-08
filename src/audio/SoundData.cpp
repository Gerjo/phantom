#include "pch.h"
#include "SoundData.h"

namespace phantom {
    SoundData::SoundData(void) : state(0), bufferID(0), sourceID(0), format(0), freq(0), channels(0), bitsPerSample(0), bufferData(0) {
    }

    SoundData::~SoundData(void) {
    }
}
