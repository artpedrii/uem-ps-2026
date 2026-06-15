#ifndef RPNG_H
#define RPNG_H

// Load a PNG file image data
//  - Color channels are returned by reference, supported values: 1 (GRAY), 2 (GRAY+ALPHA), 3 (RGB), 4 (RGBA)
//  - Bit depth is returned by reference, supported values: 8 bit, 16 bit
//  - In case data can not be loaded, returns NULL
char *rpng_load_image(const char *filename, int *width, int *height, int *color_channels, int *bit_depth);

// Save a PNG file from image data (IHDR, IDAT, IEND)
//  - Color channels defines pixel color channels, supported values: 1 (GRAY), 2 (GRAY+ALPHA), 3 (RGB), 4 (RGBA)
//  - Bit depth defines every color channel size, supported values: 8 bit, 16 bit
//  - Returns saving process result: 0-SUCCESS
int rpng_save_image(const char *filename, const char *data, int width, int height, int color_channels, int bit_depth);

#endif  // RPNG_H
