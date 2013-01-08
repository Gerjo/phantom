#ifndef SOUNDLOADER_H_
#define SOUNDLOADER_H_

namespace phantom {
    class SoundData;
    class SoundLoader
    {
    public:
        static void loadVorbis(const char *file, SoundData *data);
    };
}

#endif // !SOUNDLOADER_H_