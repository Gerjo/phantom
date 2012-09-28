#include "PNGImage.h"
#include <png.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace phantom
{
    PNGImage::PNGImage(string filename, float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->_width = width;
        this->_height = height;

        createPNG(filename);
        createRectangle();
    }

    PNGImage::~PNGImage() {
        Shape::~Shape();
        delete[] imageData;
        delete[] row_pointers;
    }

    void PNGImage::createRectangle() {
        addVertex(0.0f, 0.0f, 0.0f, 0.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
        addVertex(0.0f, _height, 0.0f, 1.0f);

        addVertex(0.0f, _height, 0.0f, 1.0f);
        addVertex(_width, _height, 1.0f, 1.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
    }

    void PNGImage::createPNG(std::string filename) {
        //header for testing if it is a png
        png_byte header[8];

        //open file as binary
        FILE *fp = fopen(filename.c_str(), "rb");
        if (!fp) {
            return;
        }

        //read the header
        fread(header, 1, 8, fp);

        //test if png
        int is_png = !png_sig_cmp(header, 0, 8);
        if (!is_png) {
            fclose(fp);
            return;
        }

        //create png struct
        png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL,
            NULL, NULL);
        if (!png_ptr) {
            fclose(fp);
            return;
        }

        //create png info struct
        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr) {
            png_destroy_read_struct(&png_ptr, (png_infopp) NULL, (png_infopp) NULL);
            fclose(fp);
            return;
        }

        //create png info struct
        png_infop end_info = png_create_info_struct(png_ptr);
        if (!end_info) {
            png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
            fclose(fp);
            return;
        }

        //png error stuff, not sure libpng man suggests this.
        if (setjmp(png_jmpbuf(png_ptr))) {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return;
        }

        //init png reading
        png_init_io(png_ptr, fp);

        //let libpng know you already read the first 8 bytes
        png_set_sig_bytes(png_ptr, 8);

        // read all the info up to the image data
        png_read_info(png_ptr, info_ptr);

        //variables to pass to get info
        int bit_depth, color_type;
        png_uint_32 twidth, theight;

        // get info about png
        png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type,
            NULL, NULL, NULL);

        //update width and height based on png info
        _pngWidth = twidth;
        _pngHeight = theight;

        // Update the png info struct.
        png_read_update_info(png_ptr, info_ptr);

        // Row size in bytes.
        int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

        // Allocate the image_data as a big block, to be given to opengl
        imageData = new png_byte[rowbytes * _pngHeight];
        if (!imageData) {
            //clean up memory and close stuff
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return;
        }

        //row_pointers is for pointing to image_data for reading the png with libpng
        row_pointers = new png_bytep[_pngHeight];
        if (!row_pointers) {
            //clean up memory and close stuff
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            delete[] imageData;
            fclose(fp);
            return;
        }
        // set the individual row_pointers to point at the correct offsets of image_data
        for (int i = 0; i < _pngHeight; ++i)
            row_pointers[_pngHeight - 1 - i] = imageData + i * rowbytes;

        //read the png into image_data through row_pointers
        png_read_image(png_ptr, row_pointers);

        //clean up memory and close stuff
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);

        fclose(fp);
    }
}

