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

        /**
        * This function is called when the sound is not in the library yet.
        */
        virtual void createSound(SoundData *data) = 0;

        /**
        * This function is called once the sound is no longer needed.
        */
        virtual void destroySound(SoundData *data) = 0;

        /**
        * This function is called when you want to play an sound file.
        *
        * @param position The position unrelative to the listener.
        */
        virtual unsigned int playSound(SoundData *data, const Vector3 &position) = 0;

        /**
        * This function is called when you want to play an music file.
        */
        virtual void playMusic(SoundData *data) = 0;

        /**
        * This function is called when you want to stop a sound from playing.
        */
        virtual void stopSound(unsigned int id) = 0;

        /**
        * This function is called when you want to stop playing the music.
        */
        virtual void stopMusic(SoundData *data) = 0;

        /**
        * This function is called when you change the position of the listener.
        *
        * @param position The position of the listener.
        */
        virtual void setPosition(const Vector3& position) = 0;

    protected:
        PhantomGame *_game;
    };
}

#endif // !AUDIOENGINE_H_

