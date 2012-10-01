#include <CompileConfig.h>
#include <graphics/shapes/Shape.h>
#include <png.h>
#include <string>

using namespace std;

namespace phantom {
	class LIBEXPORT PNGImage : public Shape {
	public:
		PNGImage(string fileName, float x, float y, float width, float height);
		~PNGImage();

	private:
		png_structp _png;
		png_infop   _info;
		float		_width;
		float	 	_height;

		void readPNG(const char* fileName);
		void createRectangle();
	};
}