#include "pch.h"
#include "SoundLoader.h"
#include <audio/SoundData.h>

#include <vorbis/codec.h>
#include <vorbis/vorbisenc.h>
#include <vorbis/vorbisfile.h>
#include <utils/PhantomException.h>

namespace phantom {
    void SoundLoader::loadVorbis(const char *filename, SoundData *data) {
        const int   BUFFSIZE = 2048;
        int         bstream;
        char        tempArray[BUFFSIZE];
        long        bytes = 0;

        vorbis_info *info;
        OggVorbis_File vorbisFile;

        if(ov_fopen(filename, &vorbisFile) != 0) {
            throw PhantomException(string("Opening ogg file for decoding failed. ").append(filename));
        }

        info = ov_info(&vorbisFile, -1);
        data->channels  = info->channels;
        data->freq      = info->rate;

        do
        {
            bytes = ov_read(&vorbisFile, tempArray, BUFFSIZE, 0, 2, 1, &bstream);
            data->bufferData->insert(data->bufferData->end(), tempArray, tempArray + bytes);
        } while (bytes > 0);

        ov_clear(&vorbisFile);
    }
}
