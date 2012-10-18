#include "Text.h"

namespace phantom{
    Text::Text(float x, float y, unsigned int size,  const char *font, const char *text) {
        this->isText = true;
        this->x = x;
        this->y = y;
        this->font = font;
        this->text = text;
        this->size = size;
    }
}