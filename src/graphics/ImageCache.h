#ifndef IMAGECACHE_H_
#define IMAGECACHE_H_

#include <map>
using namespace std;
namespace phantom {
    typedef struct { 
        unsigned char *imageData;
        unsigned char **row_pointers;
    } ImageCacheItem;

    class ImageCache
    {
    public:
        static ImageCache *getInstance() {
            if(INSTANCE == 0)
                INSTANCE = new ImageCache();
            return INSTANCE;
        }

        bool isCached(const string filename) {
            if(imageCache.find(filename) == imageCache.end())
                return false;
            else
                return true;
        }

        void insertIntoCache(const string filename, unsigned char *data, unsigned char **row_pointers) {
            ImageCacheItem item;
            item.imageData = data;
            item.row_pointers = row_pointers;
            imageCache.insert(pair<const string, ImageCacheItem>(filename, item));
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
            delete [] item->imageData;
            delete [] item->row_pointers;
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

        static ImageCache *INSTANCE;
    };
}
#endif // !IMAGECACHE_H_
