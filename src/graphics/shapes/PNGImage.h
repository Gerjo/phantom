#include <CompileConfig.h>
#include <graphics\shapes\Shape.h>
#include <png.h>

namespace phantom {
	class LIBEXPORT PNGImage : public Shape {
	public:
		PNGImage(char *fileName, float x, float y, float width, float height);
		~PNGImage();

        int getImgWidth() { return _pngW; }
        int getImgHeight() { return _pngH; }
	private:
        float _width;
        float _height;
        int _pngW;
        int _pngH;

        bool validate(std::istream& source);
		void createPNG(std::istream& source);
        static void readPNG(png_structp png, png_bytep data, png_size_t length);
		void createRectangle();
	};
}