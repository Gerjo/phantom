#ifndef FREETYPELIBRARY_H_
#define FREETYPELIBRARY_H_
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <string>

#include <core/Renderer.h>
#include <graphics/FreeTypeFont.h>

namespace phantom {
    class FreeTypeLibrary
    {
    public:
        FreeTypeLibrary(Renderer *renderer);
        ~FreeTypeLibrary();

        void addFont(const char *filename, unsigned int size);
        FreeTypeFont *getFont(const char *filename, unsigned int size);

        FT_Library lib;
    private:
        Renderer *_renderer;
        std::map<const char *, FreeTypeFont> fontCache;
        void fillTextureData(unsigned int ch, FreeTypeFont::font_info_t *font, unsigned int textureWidth, unsigned char *textureData);
    };
}
#endif

