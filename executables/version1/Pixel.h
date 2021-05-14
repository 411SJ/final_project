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
    unsigned char r;   //red value

    unsigned char g;   //green value

    unsigned char b;   //blue value

    unsigned char  status;  //weather or not pixel is valid will = 0/1
};


#endif