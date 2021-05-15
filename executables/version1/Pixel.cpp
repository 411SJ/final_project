// =========================================================
///  Name:       Sourivong Thepsimoung & Jacob Hampton
///  Professor:  Jean Herve
///  Course:     CSC 412 Operating System
///  Program:    Pixel.c
// ==========================================================
#include "Pixel.h"

// =========================================================
/// creates a Pixel struct.
///
/// just a simple constructor
// ==========================================================
Pixel create_pixel(unsigned int r,unsigned int g,unsigned int b,unsigned int status){
    Pixel pix;
    pix.r = r;
    pix.g = g;
    pix.b = b;
    pix.status = status;
    return pix;
}

// =========================================================
/// Averages two pixels.
///
/// This takes in two pixels assuming both are valid
/// returns a Pixe with the average of each of the values
// ==========================================================
Pixel average_pixel(Pixel pix1, Pixel pix2){
    Pixel pix;
    pix.r = (pix1.r + pix2.r)/2;
    pix.g = (pix1.g + pix2.g)/2;
    pix.b = (pix1.b + pix2.b)/2;
    pix.status = ON;
    return pix;
}
