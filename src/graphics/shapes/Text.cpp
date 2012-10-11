#include "Text.h"

namespace phantom{
    Text::Text(float x, float y, void *font, const unsigned char* text) {
        this->isText = true;
        this->x = x;
        this->y = y;
        this->font = font;
        this->text = text;
    }
}