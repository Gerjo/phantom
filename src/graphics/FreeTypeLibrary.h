#ifndef FREETYPELIBRARY_H_
#define FREETYPELIBRARY_H_
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <string>

#include <core/Renderer.h>
#include <graphics/FreeTypeFont.h>
#include <graphics/shapes/Text.h>

namespace phantom {
    class FreeTypeLibrary
    {
    public:
        FreeTypeLibrary(Renderer *renderer);
        ~FreeTypeLibrary();

        /**
        * Try getting the font. If it's not available, it will get added.
        *
        * @return Returns the font.
        * @param txt The text shape you want to get the font from.
        */
        FreeTypeFont *getFont(Text *txt);

        FT_Library lib;
    private:
        Renderer *_renderer;
        std::map<string, FreeTypeFont> fontCache;

        /**
        * This function adds a font to the font library.
        *
        * @param filename The location of the font relative to the working directory.
        * @param size The font size.
        */
        void addFont(const char *filename, unsigned int size);

        void fillTextureData(unsigned int ch, FreeTypeFont::font_info_t *font, unsigned int textureWidth, unsigned char *textureData);
    };
}
#endif

