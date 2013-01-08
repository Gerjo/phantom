#include "pch.h"
#include "OpenALEngine.h"

#include <utils/PhantomException.h>

namespace phantom {
    OpenALEngine::OpenALEngine(void) {
        _device = alcOpenDevice(nullptr);
        if(!_device) throw PhantomException("Failed to create OpenAL device.");

        _context = alcCreateContext(_device, NULL);
        alcMakeContextCurrent(_context);
        if(!_context) throw PhantomException("Failed to create OpenAL context.");
    }

    OpenALEngine::~OpenALEngine(void) {
        alcDestroyContext(_context);
        alcCloseDevice(_device);
    }

    void OpenALEngine::createSound(SoundData *data) {
        if(data->channels == 1) {
            data->format = data->bitsPerSample == 8 ? AL_FORMAT_MONO8 : AL_FORMAT_MONO16;
        }
        else if(data->channels == 2) {
            data->format = data->bitsPerSample == 8 ? AL_FORMAT_STEREO8 : AL_FORMAT_STEREO16;
        }

        alGenSources(1, &data->sourceID);
        alGenBuffers(1, &data->bufferID);

        alBufferData(data->bufferID, data->format, &data->bufferData[0], static_cast<ALsizei>(data->bufferData.size()), data->freq);
        alSourcei(data->sourceID, AL_BUFFER, data->bufferID);
    }

    void OpenALEngine::destroySound(SoundData *data) {
        alDeleteBuffers(1, &data->bufferID);
        alDeleteSources(1, &data->sourceID);
    }

    void OpenALEngine::playSound(SoundData *data) {
        alSourcePlay(data->sourceID);
    }

    void OpenALEngine::stopSound(SoundData *data) {
        alSourceStop(data->sourceID);
    }

    void OpenALEngine::playMusic(SoundData *data) {
        playSound(data);
    }

    void OpenALEngine::stopMusic(SoundData *data) {
        stopSound(data);
    }
}