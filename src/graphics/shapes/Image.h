#include <CompileConfig.h>
#include <graphics/shapes/Shape.h>
#include <png.h>
#include <string>
#include <graphics/ImageCache.h>

namespace phantom {
	class LIBEXPORT Image : public Shape {
	public:
		Image(std::string filelocation, float x, float y, float width, float height);
		~Image();

        /** Returns the image associated with this shape.
        *
        * @return Returns the image associated with this shape.
        */
        ImageCacheItem *getImage() { return _imageItem; }

	private:
        float           _width;
        float           _height;
        ImageCacheItem  *_imageItem;

		void createRectangle();
	};
}