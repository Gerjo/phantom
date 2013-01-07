#ifndef OPENALENGINE_H_
#define OPENALENGINE_H_
#include <audio/AudioEngine.h>
#include <AL/al.h>
#include <AL/alc.h>

namespace phantom {
    class OpenALEngine : public AudioEngine
    {
    public:
        OpenALEngine(void);
        ~OpenALEngine(void);

        virtual void createSound(SoundData *data);

        virtual bool playSound(SoundData *data) { return false; }
        virtual bool playMusic(SoundData *data) { return false; }
        virtual bool stopSound(SoundData *data) { return false; }
        virtual bool stopMusic(SoundData *data) { return false; }

    private:
        ALCdevice   *_device;
        ALCcontext  *_context;
    };
}

#endif // !OPENALENGINE_H_
