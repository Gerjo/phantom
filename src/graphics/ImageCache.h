#ifndef IMAGECACHE_H_
#define IMAGECACHE_H_

#include <string>
#include <map>
#include <png.h>
#include <core/Renderer.h>

using namespace std;
namespace phantom {
    class ImageCacheItem {
    public:
        unsigned int width;
        unsigned int height;
        unsigned int textureID;
        unsigned char *imageData;
        unsigned char **row_pointers;
    };

    class ImageCache
    {
    public:
        static ImageCache *getInstance() {
            if(INSTANCE == 0)
                INSTANCE = new ImageCache();
            return INSTANCE;
        }

        void setRenderer(Renderer *renderer) {
            _renderer = renderer;
        }

        bool isCached(const string filename) {
            if(imageCache.find(filename) == imageCache.end())
                return false;
            else
                return true;
        }

        void insertIntoCache(const string filename, ImageCacheItem *item) {
            _renderer->addTexture(item);
            delete [] item->imageData;
            delete [] item->row_pointers;
            imageCache.insert(pair<const string, ImageCacheItem>(filename, *item));
        }

        ImageCacheItem *getFromCache(const string filename) {
            if(imageCache.find(filename) == imageCache.end()) {
                return 0;
            }
            else {
                return &imageCache.at(filename);
            }
        }

        void removeFromCache(const string filename) {
            ImageCacheItem *item = &imageCache.at(filename);
            _renderer->removeTexture(item);
            imageCache.erase(filename);
        }

    private:
        ImageCache(){ };
        ~ImageCache() {
            map<const string, ImageCacheItem>::iterator it = imageCache.begin();
            for(; it != imageCache.end(); ++it) {
                ImageCacheItem *second = &(*it).second;
                delete [] second->imageData;
                delete [] second->row_pointers;
                imageCache.erase(it);
            }
        };

        map<const string, ImageCacheItem> imageCache;
        Renderer *_renderer;

        static ImageCache *INSTANCE;
    };
}
#endif // !IMAGECACHE_H_
