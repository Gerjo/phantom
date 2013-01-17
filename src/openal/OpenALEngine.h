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

        /**
        * This function creates sounds.
        *
        * @param data The sound you want to create.
        */
        virtual void createSound(SoundData *data);
        
        /**
        * This function destroys sounds.
        *
        * @param data The sound you want to destroy.
        */
        virtual void destroySound(SoundData *data);

        /**
        * This function plays a sound on a certain location. Be sure this sound is mono, else positioning won't work.
        *
        * @return Returns the sound id.
        * @param data The sound data.
        * @param position The position of the unit that's making noise.
        */
        virtual unsigned int playSound(SoundData *data, const Vector3 &position);
        
        /**
        * This function plays music.
        *
        * @param data The sound data of the music file.
        */
        virtual void playMusic(SoundData *data);

        /**
        * Stop playing a sound using the sound id returned by play sound.
        *
        * @param id The sound id.
        */
        virtual void stopSound(unsigned int id);
        
        /**
        * Stop playing the music using the sound data.
        *
        * @param data The sound data.
        */
        virtual void stopMusic(SoundData *data);

        /**
        * Set the position of the listener. This usually is the location of the camera.
        *
        * @param position The position of the listener.
        */
        virtual void setPosition(const Vector3& position);

    private:
        ALCdevice   *_device;
        ALCcontext  *_context;

        unsigned int *createSource(SoundData *data);
    };
}

#endif // !OPENALENGINE_H_
