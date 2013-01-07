#ifndef AUDIOENGINE_H_
#define AUDIOENGINE_H_

#include <CompileConfig.h>
#include <audio/SoundData.h>

namespace phantom {
    class LIBEXPORT AudioEngine
    {
    public:
        virtual void createSound(SoundData *data) = 0;

        virtual bool playSound(SoundData *data) = 0;
        virtual bool playMusic(SoundData *data) = 0;
        virtual bool stopSound(SoundData *data) = 0;
        virtual bool stopMusic(SoundData *data) = 0;
    };
}

#endif // !AUDIOENGINE_H_

