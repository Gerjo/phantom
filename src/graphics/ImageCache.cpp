#include <pch.h>
#include "ImageCache.h"

namespace phantom {
    ImageCache *ImageCache::INSTANCE = 0;

    ImageCache::ImageCache() : _renderer(nullptr) {
        std::function<void(string args)> function = [this] (string args) {
            std::stringstream str;
            str << "Size of image cache: " << this->imageCache.size();
            Console::log(str.str());
        };
        Console::mapCommand("sizeof(ImageCache)", function);
    };

    ImageCache::~ImageCache() {
        for(map<const string, ImageCacheItem>::iterator it = imageCache.begin(); it != imageCache.end(); ++it) {
            ImageCacheItem *second = &(*it).second;
            _renderer->removeTexture(second);
            delete [] second->imageData;
            second->imageData = 0;
            delete [] second->row_pointers;
            second->row_pointers = 0;
        }
        imageCache.clear();
    };

    void ImageCache::setRenderer(Renderer *renderer) {
        _renderer = renderer;
    }

    bool ImageCache::isCached(const string filename) {
        if(imageCache.find(filename) == imageCache.end())
            return false;
        else
            return true;
    }

    void ImageCache::insertIntoCache(const string filename, ImageCacheItem *item) {
        _renderer->addTexture(item);
        delete [] item->imageData;
        delete [] item->row_pointers;
        item->imageData = 0;
        item->row_pointers = 0;
        imageCache.insert(pair<const string, ImageCacheItem>(filename, *item));
        delete item;
        item = 0;
    }

    ImageCacheItem *ImageCache::getFromCache(const string filename) {
        ImageCacheItem *returnvalue = nullptr;
        try {
            returnvalue = &imageCache.at(filename);
        } catch(out_of_range &e) {
            Console::log("Is cached is not used for: " + filename + e.what());
            returnvalue = nullptr;
        }
        return returnvalue;
    }

    void ImageCache::removeFromCache(const string filename) {
        ImageCacheItem *item = &imageCache.at(filename);
        delete [] item->imageData;
        item->imageData = 0;
        delete [] item->row_pointers;
        item->row_pointers = 0;
        _renderer->removeTexture(item);
        imageCache.erase(filename);
    }
}