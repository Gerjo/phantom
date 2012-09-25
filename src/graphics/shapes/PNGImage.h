#include <CompileConfig.h>
#include <graphics\shapes\Shape.h>
#include <png.h>

namespace phantom {
	class LIBEXPORT PNGImage : public Shape {
	public:
		PNGImage(){ }
		~PNGImage(){ }
		
	private:
		png_structp _struct;
		png_infop _info;
		png_bytep _img;

		void readPNG(char* fileName) {
		    /*char header[8];    // 8 is the maximum size that can be checked

       
			FILE *fp = fopen(file_name, "rb");
			if (!fp)
					abort_("[read_png_file] File %s could not be opened for reading", file_name);
			fread(header, 1, 8, fp);
			if (png_sig_cmp(header, 0, 8))
					abort_("[read_png_file] File %s is not recognized as a PNG file", file_name);


      
			png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

			if (!png_ptr)
					abort_("[read_png_file] png_create_read_struct failed");

			info_ptr = png_create_info_struct(png_ptr);
			if (!info_ptr)
					abort_("[read_png_file] png_create_info_struct failed");

			if (setjmp(png_jmpbuf(png_ptr)))
					abort_("[read_png_file] Error during init_io");

			png_init_io(png_ptr, fp);
			png_set_sig_bytes(png_ptr, 8);

			png_read_info(png_ptr, info_ptr);

			width = png_get_image_width(png_ptr, info_ptr);
			height = png_get_image_height(png_ptr, info_ptr);
			color_type = png_get_color_type(png_ptr, info_ptr);
			bit_depth = png_get_bit_depth(png_ptr, info_ptr);

			number_of_passes = png_set_interlace_handling(png_ptr);
			png_read_update_info(png_ptr, info_ptr);


        
			if (setjmp(png_jmpbuf(png_ptr)))
					abort_("[read_png_file] Error during read_image");

			row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
			for (y=0; y<height; y++)
					row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr,info_ptr));

			png_read_image(png_ptr, row_pointers);

			fclose(fp);*/
		};
	};
}


/*

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

*/