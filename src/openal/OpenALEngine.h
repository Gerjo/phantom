#ifndef OPENALENGINE_H_
#define OPENALENGINE_H_
#include <audio/AudioEngine.h>
#include <AL/al.h>
#include <AL/alc.h>

namespace phantom {
    class OpenALEngine : public AudioEngine
    {
    public:
        OpenALEngine(PhantomGame *game);
        ~OpenALEngine(void);

        virtual void createSound(SoundData *data);
        virtual void destroySound(SoundData *data);

        virtual unsigned int playSound(SoundData *data, const Vector3 &position);
        virtual void playMusic(SoundData *data);
        virtual void stopSound(unsigned int id);
        virtual void stopMusic(SoundData *data);

        virtual void setPosition(const Vector3& position);

    private:
        ALCdevice   *_device;
        ALCcontext  *_context;

        unsigned int *createSource(SoundData *data);
    };
}

#endif // !OPENALENGINE_H_
