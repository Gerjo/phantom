#include "FreeTypeLibrary.h"
#include <iostream>

#include <freetype/ftglyph.h>

namespace phantom {
    FreeTypeLibrary::FreeTypeLibrary(Renderer *renderer) {
        if(FT_Init_FreeType(&lib)) {
            std::cout << "Failed to initialize the freetype library." << std::endl;
        }

        _renderer = renderer;
    }

    FreeTypeLibrary::~FreeTypeLibrary() {
        FT_Done_FreeType(lib);
    }

    void FreeTypeLibrary::addFont(const char *fontname, unsigned int size) {
        const unsigned int charcount = 512;
        const unsigned int maxTextureWidth = 2048;
        FreeTypeFont *font = new FreeTypeFont();
        FT_Face face;
        if(FT_New_Face(lib, fontname, 0, &face))
            std::cout << "Failed to create font with the name: " << fontname;
        if(FT_Set_Char_Size(face, size << 6, size << 6, 96, 96))
            std::cout << "Failed to load font with the name: " << fontname;
        font->info.characters.resize(charcount);
        font->info.maxHeight = 0;
        int maxWidth = 0, maxRows = 0;
        for(unsigned int ch = 0; ch < charcount; ++ch) {
            if(FT_Load_Glyph(face, FT_Get_Char_Index(face, ch), FT_LOAD_NO_HINTING))
                std::cout << "Failed to load glyph";
            FT_Glyph glyph;
            if(FT_Get_Glyph(face->glyph, &glyph))
                std::cout << "Failed to get glyph";
            FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL, 0, 1);
            FT_BitmapGlyph bmpGlyph = (FT_BitmapGlyph) glyph;
            FT_Bitmap &bmp = bmpGlyph->bitmap;
            FreeTypeFont::char_info_t* charInfo = &font->info.characters[ch];
            charInfo->width = bmp.width;
            charInfo->height = bmp.rows;
            charInfo->bitmap = new unsigned int[2 * charInfo->width * charInfo->height];
            unsigned int* charBmp = charInfo->bitmap;
            for(int j = 0; j < charInfo->height; ++j)
                for(int i = 0; i < charInfo->width; ++i)
                    charBmp[2*(i+j*charInfo->width)] = charBmp[2*(i+j*charInfo->width)+1] = 
                        (i>=bmp.width || j>=bmp.rows) ? 0 : bmp.buffer[i + bmp.width*j];
            maxWidth += charInfo->width;
            if(maxWidth >= maxTextureWidth) {
                maxWidth = charInfo->width;
                maxRows++;
            }
            if(charInfo->height > font->info.maxHeight)
                font->info.maxHeight = charInfo->height;
            charInfo->row = maxRows;
            charInfo->left = bmpGlyph->left;
            charInfo->top = bmpGlyph->top;
            charInfo->advance = face->glyph->advance.x >> 6;
            charInfo->x = maxWidth - charInfo->width;
        }
        
        int rval = 1;
        while(rval < font->info.maxHeight*(maxRows+1)) rval<<=1;
        int textureHeight = rval;
        unsigned char *textureData = new unsigned char[maxTextureWidth*textureHeight*2];
        for(unsigned int ch = 0; ch < charcount; ++ch) {
            FreeTypeFont::char_info_t *charInfo = &font->info.characters[ch];
            charInfo->y = font->info.maxHeight * charInfo->row;
            fillTextureData(ch, &font->info, maxTextureWidth, textureData);
            charInfo->uv[0].u = (float) charInfo->x / maxTextureWidth;
            charInfo->uv[0].v = (float) (charInfo->y + charInfo->height)/textureHeight;
            charInfo->vertice[0].x = 0.0f;
            charInfo->vertice[0].y = charInfo->height;
            charInfo->uv[1].u = (float) charInfo->x / maxTextureWidth;
            charInfo->uv[1].v = (float) charInfo->y / textureHeight;
            charInfo->vertice[1].x = 0.0f;
            charInfo->vertice[1].y = 0.0f;
            charInfo->uv[2].u = (float) (charInfo->x + charInfo->width) / maxTextureWidth;
            charInfo->uv[2].v = (float) (float) charInfo->y / textureHeight;
            charInfo->vertice[2].x = charInfo->width;
            charInfo->vertice[2].y = 0.0f;
            charInfo->uv[3].u = (float) (charInfo->x + charInfo->width) / maxTextureWidth;
            charInfo->uv[3].v = (float) (charInfo->y + charInfo->height) / textureHeight;
            charInfo->vertice[3].x = charInfo->width;
            charInfo->vertice[3].y = charInfo->height;
            delete [] font->info.characters[ch].bitmap;
        }
        font->texture = new ImageCacheItem();
        font->texture->imageData = (unsigned char *)textureData;
        font->texture->width = maxTextureWidth;
        font->texture->height = textureHeight;
        _renderer->addTexture(font->texture, true);
        FT_Done_Face(face);
        fontCache.insert(std::pair<const char *, FreeTypeFont>(fontname, *font));
        delete font;
    }

    FreeTypeFont *FreeTypeLibrary::getFont(Text *txt) {
        if(fontCache.find(txt->font) == fontCache.end())
            addFont(txt->font, txt->size);
        if(txt->verticesCount == 0) {
            txt->genVertices(txt->text, &fontCache.at(txt->font));
            txt->buildShape(_renderer);
        }
        return &fontCache.at(txt->font);
    }

    void FreeTypeLibrary::fillTextureData(unsigned int ch, FreeTypeFont::font_info_t *font, unsigned int textureWidth, unsigned char *textureData) {
        FreeTypeFont::char_info_t* char_info = &font->characters[ch];
        unsigned int* char_bmp = char_info->bitmap;

        int bmp_pos = 0;
        int tex_pos = 0;

        int char_x = char_info->x;
        int char_y = char_info->y;
        int char_width = char_info->width;
        int char_height = char_info->height;

        for(int bmp_y=0; bmp_y<char_height; bmp_y++)
        {
            for(int bmp_x=0; bmp_x<char_width; bmp_x++)
            {
                bmp_pos = 2 * ( bmp_x + bmp_y * char_width);
                tex_pos = 2 * ( (char_x + bmp_x) + ( (char_y + bmp_y) * textureWidth) );

                textureData[tex_pos] = char_bmp[bmp_pos];
                textureData[tex_pos+1] = char_bmp[bmp_pos+1];
            }
        }
    }
}
