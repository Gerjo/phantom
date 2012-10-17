#include "FreeTypeLibrary.h"
#include <iostream>

FreeTypeLibrary::FreeTypeLibrary() {
    if(FT_Init_FreeType(&lib)) {
        std::cout << "Failed to initialize the freetype library." << std::endl;
    }
}


FreeTypeLibrary::~FreeTypeLibrary() {
    //TODO: delete fonts;
}

void FreeTypeLibrary::addFont(const std::string fontname) {
    FT_Face face;
    if(FT_New_Face(lib, fontname.c_str(), 0, &face)) {
        fprintf(stderr, "Could not open font %s\n", fontname.c_str());
        return;
    }
    fontCache.insert(std::pair<const std::string, FT_Face>(fontname, face));
}

FT_Face *FreeTypeLibrary::getFont(const std::string *fontname) {
    if(fontCache.find(*fontname) == fontCache.end()) {
        addFont(*fontname);
        return &fontCache.at(*fontname);
    }
    else {
        return &fontCache.at(*fontname);
    }
}