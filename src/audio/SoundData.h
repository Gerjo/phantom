#ifndef SOUNDDATA_H_
#define SOUNDDATA_H_

#include <vector>
#include <deque>

namespace phantom {
    class SoundData
    {
    public:
        int state;
        unsigned int bufferID;
        std::deque<unsigned int> sourceID;
        int format;
        int freq;

        int channels;
        int bitsPerSample;

        std::vector<char> *bufferData;

        SoundData(void);
        ~SoundData(void);
    };
}
#endif // !SOUNDDATA_H_