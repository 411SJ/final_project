#include "Pixel.h"

Pixel create_pixel(unsigned int r,unsigned int g,unsigned int b,unsigned int status){
    Pixel pix;
    pix.r = r;
    pix.g = g;
    pix.b = b;
    pix.status = status;
    return pix;
}

Pixel average_pixel(Pixel pix1, Pixel pix2){
    Pixel pix;
    pix.r = (pix1.r + pix2.r)/2;
    pix.g = (pix1.g + pix2.g)/2;
    pix.b = (pix1.b + pix2.b)/2;
    pix.status = ON;
    return pix;
}
