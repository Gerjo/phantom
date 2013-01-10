#ifndef SOUNDS_H_
#define SOUNDS_H_

#include <core/Composite.h>

namespace phantom {
    class SoundData;
    class LIBEXPORT Sounds : public Composite
    {
    public:
        Sounds(void);
        ~Sounds(void);

        /**
        * The function playSound should be called by the game when an audio file has to be played.
        *
        * @param filename The location of the file.
        * @param position The position of the object on the map unrelative to the listener.
        */
        int     playSound(const string &filename, const Vector3 &position);

        /**
        * The function stopSound should be called when you want to stop the sound from playing.
        *
        * @param id The sound id that has been returned by the playSound function.
        */
        bool    stopSound(int id);

        /**
        * The function playMusic should be called when you want to play music gapless in looping mode.
        *
        * @param filename The location of the music file.
        */
        int     playMusic(const string &filename);
        
        /**
        * The function stopMusic should be called when you want to stop music.
        *
        * @param filename The location of the music file.
        */
        bool    stopMusic(const string &filename);

    private:
        /**
        * This function returns true if a file is in the sound cache.
        */
        bool    isCached(const string &filename);
        
        /**
        * This function inserts a file into the sound cache.
        */
        void    insertIntoCache(const string &filename);

        std::map<const std::string, SoundData*> _soundMap;
    };

}
#endif // SOUNDS_H_
