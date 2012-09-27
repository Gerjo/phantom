#include "PNGImage.h"
#include <png.h>

namespace phantom
{
	PNGImage::PNGImage(char *fileName, float x, float y, float width, float height) {
		this->x = x;
		this->y = y;
		this->_width = width;
		this->_height = height;
		readPNG(fileName);
		createRectangle();
	}

	PNGImage::~PNGImage() {
		for (unsigned int y = 0; y < png_get_image_height(_png, _info); ++y)
			free(_img[y]);
		free(_img);
	}

	void PNGImage::createRectangle() {
		addVertex(0.0f, 0.0f, 0.0f, 0.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
        addVertex(0.0f, _height, 0.0f, 1.0f);

        addVertex(0.0f, _height, 0.0f, 1.0f);
        addVertex(_width, _height, 1.0f, 1.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
	}

	void PNGImage::readPNG(char *fileName) {
		char header[8];

		FILE *fp = fopen(fileName, "rb");
		fread(header, 1, 8, fp);
		_png = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
		_info = png_create_info_struct(_png);
			
		setjmp(png_jmpbuf(_png));
		png_init_io(_png, fp);
		png_set_sig_bytes(_png, 8);
		png_read_info(_png, _info);

		int width           = png_get_image_width(_png, _info);
		int height          = png_get_image_height(_png, _info);
		png_byte color_type = png_get_color_type(_png, _info);
		png_byte bit_depth  = png_get_bit_depth(_png, _info);

		int number_of_passes = png_set_interlace_handling(_png);
		png_read_update_info(_png, _info);

		setjmp(png_jmpbuf(_png));
		_img = (png_bytep*) malloc(sizeof(png_bytep) * height);
		for (int y = 0; y < height; ++y)
				_img[y] = (png_byte*) malloc(png_get_rowbytes(_png, _info));

		png_read_image(_png, _img);
	}
}

