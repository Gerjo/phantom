#ifndef SPRITE_H
#define	SPRITE_H

#include <core/Composite.h>
#include <graphics/Graphics.h>

namespace phantom {

class Sprite : public Composite {
public:
    Sprite(void);

protected:
    Graphics graphics;
};

}

#endif	/* SPRITE_H */

