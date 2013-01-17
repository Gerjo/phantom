#include <pch.h>
#include "Image.h"
#include <graphics/ImageCache.h>
#include <graphics/ImageLoader.h>

namespace phantom
{
    Image::Image(const std::string filelocation, float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->_width = width;
        this->_height = height;
        isImage = true;

        ImageCache *imageCache = ImageCache::getInstance();

        if(!imageCache->isCached(filelocation)) {
            imageCache->insertIntoCache(filelocation, ImageLoader::createPNG(filelocation));
        }
        _imageItem = imageCache->getFromCache(filelocation);

        createRectangle();
    }

    Image::~Image() {

    }

    void Image::createRectangle() {
        addVertex(0.0f, 0.0f, 0.0f, 0.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
        addVertex(0.0f, _height, 0.0f, 1.0f);

        addVertex(0.0f, _height, 0.0f, 1.0f);
        addVertex(_width, _height, 1.0f, 1.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
    }
}

