#ifndef AUDIOENGINE_H_
#define AUDIOENGINE_H_

#include <CompileConfig.h>
#include <audio/SoundData.h>
#include <core/PhantomGame.h>

namespace phantom {
    class LIBEXPORT AudioEngine
    {
    public:
        AudioEngine(PhantomGame *game) {
            _game = game;
        }

        virtual void createSound(SoundData *data) = 0;
        virtual void destroySound(SoundData *data) = 0;

        virtual unsigned int playSound(SoundData *data, const Vector3 &position) = 0;
        virtual void playMusic(SoundData *data) = 0;
        virtual void stopSound(unsigned int id) = 0;
        virtual void stopMusic(SoundData *data) = 0;

        virtual void setPosition(const Vector3& position) = 0;

    protected:
        PhantomGame *_game;
    };
}

#endif // !AUDIOENGINE_H_

