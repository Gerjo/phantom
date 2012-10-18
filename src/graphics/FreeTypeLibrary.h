#ifndef FREETYPELIBRARY_H_
#define FREETYPELIBRARY_H_
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <string>

class FreeTypeLibrary
{
public:
    FreeTypeLibrary();
    ~FreeTypeLibrary();

    void addFont(const std::string filename, float size);
    FT_Face *getFont(const std::string *filename, float size);

    FT_Library lib;
private:
    std::map<const std::string, FT_Face> fontCache;
};

#endif

