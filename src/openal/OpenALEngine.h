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
        virtual void destroySound(SoundData *data);

        virtual void playSound(SoundData *data);
        virtual void playMusic(SoundData *data);
        virtual void stopSound(SoundData *data);
        virtual void stopMusic(SoundData *data);

    private:
        ALCdevice   *_device;
        ALCcontext  *_context;
    };
}

#endif // !OPENALENGINE_H_
