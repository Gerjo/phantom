#include "ImageLoader.h"
#include <png.h>

namespace phantom {
    ImageCacheItem *ImageLoader::createPNG(const std::string filename) {
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
            printf("File could not be initialized: %s\n", filename.c_str());
            return 0;
        }

        // Read the header and see if it is a real PNG.
        fread(header, 1, 8, fp);
        if (png_sig_cmp(header, 0, 8)) {
            fclose(fp);
            return 0;
        }

        // Create the PNG struct.
        png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
        if (!png_ptr) {
            fclose(fp);
            return 0;
        }

        // Create the png info struct.
        info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr) {
            png_destroy_read_struct(&png_ptr, (png_infopp) 0, (png_infopp) 0);
            fclose(fp);
            return 0;
        }

        // Check for the end of the info struct.
        end_info = png_create_info_struct(png_ptr);
        if (!end_info) {
            png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) 0);
            fclose(fp);
            return 0;
        }

        // For error handling.
        if (setjmp(png_jmpbuf(png_ptr))) {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return 0;
        }

        // Init imageData to contain all the image data that resides in the image.
        ImageCacheItem *img = new ImageCacheItem();

        // Getting ready to read everything.
        png_init_io(png_ptr, fp);
        png_set_sig_bytes(png_ptr, 8);
        png_read_info(png_ptr, info_ptr);
        png_get_IHDR(png_ptr, info_ptr, &img->width, &img->height, &bit_depth, &color_type, 0, 0, 0);

        png_read_update_info(png_ptr, info_ptr);

        // Get the size of each row.
        rowbytes = png_get_rowbytes(png_ptr, info_ptr);

        img->imageData = new png_byte[rowbytes * img->height];
        if (!img->imageData) {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            fclose(fp);
            return 0;
        }

        // Init the row pointers.
        img->row_pointers = new png_bytep[img->height];
        if (!img->row_pointers) {
            png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
            delete[] img->imageData;
            fclose(fp);
            return 0;
        }
        
        // Make the row pointers point to the actual data in one row (1 y-axis line).
        for (unsigned int i = 0; i < img->height; ++i)
            //img->row_pointers[img->height - 1 - i] = img->imageData + (i * rowbytes);
                img->row_pointers[i] = img->imageData + (i * rowbytes);

        // Actually read the image.
        png_read_image(png_ptr, img->row_pointers);

        // Cleanup.
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);

        fclose(fp);

        return img;
    }
}

phantom::ImageLoader *phantom::ImageLoader::INSTANCE = 0;