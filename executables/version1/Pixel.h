// =========================================================
///  Name:       Sourivong Thepsimoung & Jacob Hampton
///  Professor:  Jean Herve
///  Course:     CSC 412 Operating System
///  Program:    Pixel.h
// ==========================================================

#ifndef PIXEL_H
#define PIXEL_H

using namespace std;
/// boolean ON
const unsigned char ON = 1;     
/// boolean OFF
const unsigned char OFF = 0;    

// =========================================================
/// struct to represent an rgb pixel
/// 
/// made so that moving pixel data from the satalite
/// to the map is simpilar 
// ==========================================================
struct Pixel
{
    /// red value
    unsigned int r;   
    /// green value
    unsigned int g;
    /// blue value   
    unsigned int b;   
    /// weather or not pixel is valid will = 0/1
    unsigned int  status; 
};
/// Pixel constructor
Pixel create_pixel(unsigned int r,unsigned int g,unsigned int b,unsigned int status);

/// Average two Pixels
Pixel average_pixel(Pixel pix1, Pixel pix2);

#endif