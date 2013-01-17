#ifndef IMAGELOADER_H_
#define IMAGELOADER_H_

#include <string>
#include "ImageCache.h"

using namespace std;
namespace phantom {

    class ImageLoader
    {
    public:
        /**
        * Load a PNG and store it in an ImageCacheItem
        *
        * @return Returns the ImageCacheItem created.
        * @param filename The Location of the image relative to the working directory.
        */
        static ImageCacheItem *createPNG(const std::string filename);
    };
}
#endif // !IMAGELOADER_H_
