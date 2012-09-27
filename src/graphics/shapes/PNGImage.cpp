#include "PNGImage.h"
#include <png.h>
#include <iostream>
#include <fstream>

using namespace std;

namespace phantom
{
    PNGImage::PNGImage(char *fileName, float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->_width = width;
        this->_height = height;
        
        ifstream inputFile;
        inputFile.open(fileName, ifstream::binary);
        if(!validate(inputFile)) {
            cout << "Could not verify PNG." << endl;
            return;
        }

        createPNG(inputFile);
        createRectangle();
    }

    PNGImage::~PNGImage() {
        delete[] (png_bytep)_imgRows;
    }

    void PNGImage::createRectangle() {
        addVertex(0.0f, 0.0f, 0.0f, 0.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
        addVertex(0.0f, _height, 0.0f, 1.0f);

        addVertex(0.0f, _height, 0.0f, 1.0f);
        addVertex(_width, _height, 1.0f, 1.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
    }

    bool PNGImage::validate(std::istream& source) {
        png_byte pngsig[8];
        int is_png = 0;

        source.read((char*)pngsig, 8);

        if(!source.good()) return false;

        is_png = png_sig_cmp(pngsig, 0, 8);
        return (is_png == 0);
    }

    void PNGImage::readPNG(png_structp png, png_bytep data, png_size_t length) {
        png_voidp a = png_get_io_ptr(png);
        ((istream*)a)->read((char*)data, length);
    }

    void PNGImage::createPNG(std::istream& source) {
        png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
        if(!png) {
            cout << "Error in create read struct." << endl;
            return;
        }

        png_infop info = png_create_info_struct(png);
        if(!info) {
            cout << "Error creating info struct." << endl;
            png_destroy_read_struct(&png, 0, 0);
            return;
        }
        
        _imgRows = 0;
        char* data = 0;

        if(setjmp(png_jmpbuf(png))) {
            png_destroy_read_struct(&png, &info, 0);
            cout << "Error occurred while reading the file." << endl;
            return;
        }

        png_set_read_fn(png, (png_voidp)&source, readPNG);
        
        png_set_sig_bytes(png, 8);
        png_read_info(png, info);

        _pngW = png_get_image_width(png, info);
        _pngH = png_get_image_height(png, info);

        png_uint_32 bitdepth   = png_get_bit_depth(png, info);
        png_uint_32 channels   = png_get_channels(png, info);
        unsigned int colorType = png_get_color_type(png, info);

        if(png_get_valid(png, info, PNG_INFO_tRNS)) {
            png_set_tRNS_to_alpha(png);
            channels++;
        }

        if (bitdepth == 16) {
            png_set_strip_16(png);
        }

        _imgRows = new png_bytep[_pngH];
        data = new char[_pngW * _pngH * bitdepth * channels / 8];
        const unsigned int stride = _pngW * bitdepth * channels / 8;

        for(size_t i = 0; i < _pngH; ++i) {
            png_uint_32 q = (_pngH - i - 1) * stride;
            _imgRows[i] = (png_bytep)data + q;
        }

        png_read_image(png, _imgRows);

        png_destroy_read_struct(&png, &info,(png_infopp)0);
    }
}

