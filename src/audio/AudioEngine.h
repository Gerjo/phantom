#ifndef AUDIOENGINE_H_
#define AUDIOENGINE_H_

#include <CompileConfig.h>
#include <audio/SoundData.h>

namespace phantom {
    class LIBEXPORT AudioEngine
    {
    public:
        virtual void createSound(SoundData *data) = 0;
        virtual void destroySound(SoundData *data) = 0;

        virtual void playSound(SoundData *data) = 0;
        virtual void playMusic(SoundData *data) = 0;
        virtual void stopSound(SoundData *data) = 0;
        virtual void stopMusic(SoundData *data) = 0;
    };
}

#endif // !AUDIOENGINE_H_

