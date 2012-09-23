#include "SpriteRegistry.h"

namespace phantom {

SpriteRegistry::SpriteRegistry() {

}

void SpriteRegistry::add(Sprite* sprite) {
    _sprites.push_back(sprite);
}

}

