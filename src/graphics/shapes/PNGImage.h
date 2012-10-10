#include <CompileConfig.h>
#include <graphics/shapes/Shape.h>
#include <png.h>
#include <string>

namespace phantom {
	class LIBEXPORT PNGImage : public Shape {
	public:
		PNGImage(std::string filename, float x, float y, float width, float height);
		~PNGImage();

        int getImgWidth()  { return _pngWidth; }
        int getImgHeight() { return _pngHeight; }
	private:
        float           _width;
        float           _height;
        unsigned int    _pngWidth;
        unsigned int    _pngHeight;
		
		void createRectangle();
	};
}