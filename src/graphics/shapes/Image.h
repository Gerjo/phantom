#include <CompileConfig.h>
#include <graphics/shapes/Shape.h>
#include <png.h>
#include <string>
#include <graphics/ImageCache.h>

namespace phantom {
	class LIBEXPORT Image : public Shape {
	public:
		Image(std::string filename, float x, float y, float width, float height);
		~Image();

        ImageCacheItem *getImage() { return _imageItem; }

	private:
        float           _width;
        float           _height;
        ImageCacheItem  *_imageItem;

		void createRectangle();
	};
}