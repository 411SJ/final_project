// =========================================================
//  Name:       Sourivong Thepsimoung & Jacob Hampton
//  Professor:  Jean Herve
//  Course:     CSC 412 Operating System
//  Program:    Map.h
// ==========================================================

#ifndef PIXEL_H
#define PIXEL_H

using namespace std;

const unsigned char ON = 1;     //pixel is valid

const unsigned char OFF = 0;    //pixel is invalid 

struct Pixel
{
    unsigned int r;   //red value

    unsigned int g;   //green value

    unsigned int b;   //blue value

    unsigned int  status;  //weather or not pixel is valid will = 0/1
};

Pixel create_pixel(unsigned int r,unsigned int g,unsigned int b,unsigned int status);

Pixel average_pixel(Pixel pix1, Pixel pix2);
#endif