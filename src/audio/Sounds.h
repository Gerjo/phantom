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

        int     playSounds(const string &filename);
        bool    stopSounds(int id);

    private:
        bool    isCached(const string &filename);
        void    insertIntoCache(const string &filename);

        std::map<const std::string, SoundData*> _soundMap;
    };

}
#endif // SOUNDS_H_
