#include "Pixel.h"

Pixel createPixel(char r,char g, char b, char status){
    Pixel pix;
    pix.r = r;
    pix.g = g;
    pix.b = b;
    pix.status = status;
    return pix;
}