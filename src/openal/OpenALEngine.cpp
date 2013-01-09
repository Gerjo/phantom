#include "pch.h"
#include "OpenALEngine.h"
#include <utils/PhantomException.h>

namespace phantom {

    OpenALEngine::OpenALEngine(PhantomGame *game) : AudioEngine(game), _device(nullptr), _context(nullptr) {
        _device = alcOpenDevice(nullptr);
        if(_device) {
            _context = alcCreateContext(_device, NULL);
            alcMakeContextCurrent(_context);
        }
        if(!_context)
            throw PhantomException("Failed to create OpenAL context.");

        ALfloat lorientation[] = { 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f }; // First 3 are the at vector and last 3 are the up vector
        ALfloat lvelocity[] = { 0.0f, 0.0f, 0.0f };
        alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
        alListenerfv(AL_ORIENTATION, lorientation);
        alListenerf(AL_GAIN, 1.0f); // Master volume
    }

    OpenALEngine::~OpenALEngine(void) {
        alcMakeContextCurrent(nullptr);
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

        alGenBuffers(1, &data->bufferID);

        alBufferData(data->bufferID, data->format, &data->bufferData->at(0), static_cast<ALsizei>(data->bufferData->size()), data->freq);

        // We don't need the bufferData anymore.
        delete data->bufferData;
        data->bufferData = nullptr;
    }

    unsigned int *OpenALEngine::createSource(SoundData *data) {
        data->sourceID.push_back(unsigned int());
        alGenSources(1, &(*(data->sourceID.end() - 1)));
        alSourcei(*(data->sourceID.end() - 1), AL_BUFFER, data->bufferID);

        return &(*(data->sourceID.end() - 1));
    }

    void OpenALEngine::destroySound(SoundData *data) {
        for(auto source = data->sourceID.begin(); source != data->sourceID.end(); ++source) {
            alDeleteSources(1, &(*source));
        }
        data->sourceID.clear();

        alDeleteBuffers(1, &data->bufferID);
    }

    unsigned int OpenALEngine::playSound(SoundData *data, const Vector3 &position) {
        const unsigned int &sourceID = *createSource(data);

        alSourcef(sourceID, AL_GAIN, _game->soundvol);
        alSource3f(sourceID, AL_POSITION, position.x, position.y, position.z);
        alSourcef(sourceID, AL_REFERENCE_DISTANCE, _game->getViewPort().x);

        alSourcePlay(sourceID);

        return sourceID;
    }

    void OpenALEngine::stopSound(unsigned int id) {
        alSourceStop(id);
    }

    void OpenALEngine::playMusic(SoundData *data) {
        if(data->sourceID.size() < 1) {
            const unsigned int &sourceID = *createSource(data);
            alSourcef(sourceID, AL_GAIN, _game->musicvol);
            alSourcei(sourceID, AL_LOOPING, AL_TRUE);
            alSourcePlay(sourceID);
        }
        else {
            throw PhantomException("This file is already playing! ID: " + data->bufferID);
        }
    }

    void OpenALEngine::stopMusic(SoundData *data) {
        stopSound(data->sourceID[0]);
        alDeleteSources(1, &data->sourceID[0]);
        data->sourceID.erase(data->sourceID.begin());
    }

    void OpenALEngine::setPosition(const Vector3& position) {
        alListener3f(AL_POSITION, position.x, position.y, position.z);
    }
}