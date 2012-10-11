#include "PNGImage.h"
#include <graphics/ImageCache.h>
#include <iostream>
#include <fstream>
#include <string>
#include <graphics/ImageLoader.h>

namespace phantom
{
    PNGImage::PNGImage(const std::string filename, float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->_width = width;
        this->_height = height;
        isImage = true;
        
        ImageCache *imageCache = ImageCache::getInstance();

        if(!imageCache->isCached(filename)) {
            imageCache->insertIntoCache(filename, ImageLoader::createPNG(filename));
        }
        _imageItem = imageCache->getFromCache(filename);
        
        createRectangle();
    }

    PNGImage::~PNGImage() {
        
    }

    void PNGImage::createRectangle() {
        addVertex(0.0f, 0.0f, 0.0f, 0.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
        addVertex(0.0f, _height, 0.0f, 1.0f);

        addVertex(0.0f, _height, 0.0f, 1.0f);
        addVertex(_width, _height, 1.0f, 1.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
    }
}

