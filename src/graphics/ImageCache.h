#ifndef IMAGECACHE_H_
#define IMAGECACHE_H_


#include <map>
#include <string>
#include <png.h>
#include <core/Renderer.h>
#include <stdexcept>

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
            if(INSTANCE == 0) {
                INSTANCE = new ImageCache();
            }
            return INSTANCE;
        }

        ~ImageCache();

        /**
        * Sets the renderer for adding and removing textures.
        *
        * @param renderer The renderer that's being used in the game.
        */
        void setRenderer(Renderer *renderer);

        /**
        * Returns true if the image is cached.
        *
        * @return Returns true if the image is cached.
        */
        bool isCached(const string filename);

        /**
        * Insert an image into the cache.
        *
        * @params filename The location of an image relative to the working directory.
        * @params item The ImageCacheItem you want to add to the cache.
        */
        void insertIntoCache(const string filename, ImageCacheItem *item);

        /**
        * Get an image that's located in the cache.
        *
        * @return Returns nullptr if nothing is found, else it returns the item.
        * @param filename The location relative to the working directory.
        */
        ImageCacheItem *getFromCache(const string filename);

        /**
        * Remove an image from the cache.
        *
        * @param filename The location of the image relative to the working directory.
        */
        void removeFromCache(const string filename);

    private:
        ImageCache();

        map<const string, ImageCacheItem> imageCache;
        Renderer *_renderer;

        static ImageCache *INSTANCE;
    };
}
#endif // !IMAGECACHE_H_
