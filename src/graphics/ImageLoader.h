#ifndef IMAGELOADER_H_
#define IMAGELOADER_H_

#include <string>
#include "ImageCache.h"

using namespace std;
namespace phantom {

    class ImageLoader
    {
    public:
        static ImageCacheItem *createPNG(const std::string filename);

    private:
        ImageLoader(){ };
        ~ImageLoader() { };
        static ImageLoader *INSTANCE;
    };
}
#endif // !IMAGELOADER_H_
