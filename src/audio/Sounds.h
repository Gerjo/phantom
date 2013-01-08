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

        int     playSound(const string &filename, const Vector3 &position);
        bool    stopSound(int id);

        int     playMusic(const string &filename);
        bool    stopMusic(const string &filename);

    private:
        bool    isCached(const string &filename);
        void    insertIntoCache(const string &filename);

        std::map<const std::string, SoundData*> _soundMap;
    };

}
#endif // SOUNDS_H_
