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

        std::vector<char> *bufferData; // The buffer containing the audio sample in RAW format.

        SoundData();
        ~SoundData();

    private:
        // Copying is not allowed since the buffer won't be recreated.
        SoundData(const SoundData& data) { }
    };
}
#endif // !SOUNDDATA_H_