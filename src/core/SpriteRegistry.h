#ifndef SPRITEREGISTRY_H
#define	SPRITEREGISTRY_H

#include <vector>
#include <graphics/Sprite.h>

namespace phantom {

typedef vector<Sprite*> Sprites;
typedef Sprites::iterator SpritesIterator;

class SpriteRegistry {
public:
    SpriteRegistry();
private:
    void add(Sprite* sprite);

};

}

#endif	/* SPRITEREGISTRY_H */

