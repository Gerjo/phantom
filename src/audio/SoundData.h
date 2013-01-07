#ifndef SOUNDDATA_H_
#define SOUNDDATA_H_

#include <AL/al.h>
#include <vector>

namespace phantom {
    class SoundData
    {
    public:
        ALint state;
        ALuint bufferID;
        ALuint sourceID;
        ALenum format;
        ALsizei freq;

        int channels;
        int bitsPerSample;

        std::vector<char> bufferData;

        SoundData(void);
        ~SoundData(void);
    };
}
#endif // !SOUNDDATA_H_