#ifndef SOUNDLOADER_H_
#define SOUNDLOADER_H_

namespace phantom {
    class SoundData;
    class SoundLoader
    {
    public:
        /**
        * This function loads an OGG Vorbis file into a SoundData object.
        *
        * @param file The location of the ogg file.
        * @param data The SoundData object you want to load the data in.
        */
        static void loadVorbis(const char *file, SoundData *data);
    };
}

#endif // !SOUNDLOADER_H_