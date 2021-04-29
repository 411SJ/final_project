// =========================================================
//  Name:       Sourivong Thepsimoung & Jacob Hampton
//  Professor:  Jean Herve
//  Course:     CSC 412 Operating System
//  Program:    Satalite.h
// ==========================================================

#ifndef SATALITE_H
#define SATALITE_H

#include <vector>

using namespace std;
// =================================================================
// This is the data type used to represent a satalite fragment
// and store all the important information that is used by the Map.h
// =================================================================
typedef struct Satalite
{
    unsigned int width;             // Numbers of Columns of the satalite fragment

    unsigned int height;            // Numbers of Rows of the satalite fragment

    unsigned int mapRowOrigin;      // Row Position on the larger map
  
    unsigned int mapColOrigin;      // Columns position on the larger map

    void *pixels;                   // Pointer to the pixel data that makes up the satalite fragment 

    vector<vector<char>> dat_list;  // 2D vector to store the data fragment

    unsigned int image_selection;   // Marks which .dat file belongs to for image type

} Satalite;

#endif