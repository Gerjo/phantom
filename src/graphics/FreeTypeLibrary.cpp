#include "FreeTypeLibrary.h"
#include <iostream>

FreeTypeLibrary::FreeTypeLibrary() {
    lib = new FT_Library();
    if(FT_Init_FreeType(lib)) {
        std::cout << "Failed to initialize the freetype library." << std::endl;
    }
}


FreeTypeLibrary::~FreeTypeLibrary() {
    //TODO: delete fonts;
    delete lib;
}

void FreeTypeLibrary::addFont(const std::string *fontname) {
    if(getFont(fontname) == 0) { return; }

    FT_Face *face;
    FT_New_Face(*lib, fontname->c_str(), 0, face);
    fontCache.insert(std::pair<const std::string, FT_Face *>(*fontname, face));
}

FT_Face *FreeTypeLibrary::getFont(const std::string *fontname) {
    if(fontCache.find(*fontname) == fontCache.end()) {
        return 0;
    }
    else {
        return fontCache.at(*fontname);
    }
}