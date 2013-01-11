#include <pch.h>
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

    void Text::genVertices(const char *text, FreeTypeFont *font) {
        size_t size = strlen(text);
        int advance = 0;
        
        FreeTypeFont::char_info_t* ci;
        for(int c = 0; c != size; ++c)
        {
            ci = &font->info.characters[text[c]];
            for(int i = 0; i < 4; ++i) {
                addVertex(ci->left+advance+ci->vertice[i].x, ci->vertice[i].y + (font->info.maxHeight-ci->top), ci->uv[i].u, ci->uv[i].v);
            }
            advance += ci->advance;
        }
    }
}