#include <CompileConfig.h>
#include <graphics\shapes\Shape.h>
#include <png.h>

namespace phantom {
	class LIBEXPORT PNGImage : public Shape {
	public:
		PNGImage(){ }
		~PNGImage(){ }
		
	private:
		png_structp _png;
		png_infop   _info;
		png_bytep*  _img;

		void readPNG(char* fileName) {
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
		};
	};
}