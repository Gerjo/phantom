#ifndef FREETYPEFONT_H_
#define FREETYPEFONT_H_

#include <vector>
#include <ft2build.h>
#include <graphics/VerticeData.h>
#include <graphics/ImageCache.h>

namespace phantom {
    class FreeTypeFont
    {
    public:
        struct char_info_t {
            int x, y, width, height, left, top, advance, row;
            TexCoord uv[4];
            Vertice vertice[4];
            unsigned int *bitmap;
        };

        struct font_info_t {
            int maxHeight;
            std::vector<FreeTypeFont::char_info_t> characters;
        };

        font_info_t info;
        ImageCacheItem *texture;
    };
}
#endif
