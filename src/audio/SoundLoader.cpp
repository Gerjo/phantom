#include "pch.h"
#include "SoundLoader.h"
#include <audio/SoundData.h>

#include <vorbis/codec.h>
#include <vorbis/vorbisenc.h>
#include <vorbis/vorbisfile.h>

namespace phantom {
    void SoundLoader::loadVorbis(const char *filename, SoundData *data) {
        const int   BUFFSIZE = 2048;
        int         bstream;
        char        tempArray[BUFFSIZE];
        long        bytes = 0;
        FILE        *file;

#ifndef WIN32
        fopen(filename, "rb");
#else
        fopen_s(&file, filename, "rb");
#endif

        vorbis_info *info;
        OggVorbis_File vorbisFile;

        ov_open(file, &vorbisFile, nullptr, 0);

        info = ov_info(&vorbisFile, -1);
        data->channels  = info->channels;
        data->freq      = info->rate;

        do
        {
            bytes = ov_read(&vorbisFile, tempArray, BUFFSIZE, 0, 2, 1, &bstream);
            data->bufferData.insert(data->bufferData.end(), tempArray, tempArray + bytes);
        } while (bytes > 0);

        ov_clear(&vorbisFile);
    }
}
