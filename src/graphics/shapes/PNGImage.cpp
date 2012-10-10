#include "PNGImage.h"
#include <graphics/ImageCache.h>
#include <png.h>
#include <iostream>
#include <fstream>
#include <string>

namespace phantom
{
    PNGImage::PNGImage(const std::string filename, float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->_width = width;
        this->_height = height;
        
        ImageCache *imageCache = ImageCache::getInstance();

        if(imageCache->isCached(filename)) {
            ImageCacheItem *item = imageCache->getFromCache(filename);
            imageData = item->imageData;
            row_pointers = item->row_pointers;
        }
        else {
            createPNG(filename);
            imageCache->insertIntoCache(filename, imageData, row_pointers);
        }
        createRectangle();
    }

    PNGImage::~PNGImage() {
        
    }

    void PNGImage::createRectangle() {
        addVertex(0.0f, 0.0f, 0.0f, 0.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
        addVertex(0.0f, _height, 0.0f, 1.0f);

        addVertex(0.0f, _height, 0.0f, 1.0f);
        addVertex(_width, _height, 1.0f, 1.0f);
        addVertex(_width, 0.0f, 1.0f, 0.0f);
    }

    void PNGImage::createPNG(const std::string filename) {
        png_byte    header[8];
        FILE        *fp;
        png_structp png_ptr;
        png_infop   info_ptr, end_info;
        int         bit_depth, color_type, rowbytes;

        // Open the file as binary. (Made this an ifdef because fopen_s does not exist on Linux.
        // Other option would be using ifstream.
#ifdef _WINDOWS
        fopen_s(&fp, filename.c_str(), "rb");
#else
        fp = fopen(filename.c_str(), "rb");
#endif

        // Check if the file is initialized.
        if (!fp) {
            std::cout << "File could not be initialized: " << filename.c_str() << std::endl;
            return;
        }

        // Read the header and see if it is a real PNG.
        fread(header, 1, 8, fp);
        if (png_sig_cmp(header, 0, 8)) {
            fclose(fp);
            return;
        }

        // Create the PNG struct.
        png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
        if (!png_ptr) {
            fclose(fp);
            return;
        }

        // Create the png info struct.
        info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr) {
            png_destroy_read_struct(&png_ptr, (png_infopp) 0, (png_infopp) 0);
            fclose(fp);
            return;
        }

        // Check for the end of the info struct.
        end_info = png_create_info_struct(png_ptr);
        if (!end_info) {
            png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) 0);
            fclose(fp);
            return;
        }

        // For error handling.
        if (setjmp(png_jmpbuf(png_ptr))) {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return;
        }

        // Getting ready to read everything.
        png_init_io(png_ptr, fp);
        png_set_sig_bytes(png_ptr, 8);
        png_read_info(png_ptr, info_ptr);
        png_get_IHDR(png_ptr, info_ptr, &_pngWidth, &_pngHeight, &bit_depth, &color_type, 0, 0, 0);

        png_read_update_info(png_ptr, info_ptr);

        // Get the size of each row.
        rowbytes = png_get_rowbytes(png_ptr, info_ptr);

        // Init imageData to contain all the image data that resides in the image.
        imageData = new png_byte[rowbytes * _pngHeight];
        if (!imageData) {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return;
        }

        // Init the row pointers.
        row_pointers = new png_bytep[_pngHeight];
        if (!row_pointers) {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            delete[] imageData;
            fclose(fp);
            return;
        }
        
        // Make the row pointers point to the actual data in one row (1 y-axis line).
        for (unsigned int i = 0; i < _pngHeight; ++i)
            row_pointers[_pngHeight - 1 - i] = imageData + i * rowbytes;

        // Actually read the image.
        png_read_image(png_ptr, row_pointers);

        // Cleanup.
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);

        fclose(fp);
    }
}

