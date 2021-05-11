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

    unsigned int map_Row_Origin;    // Row Position on the map
  
    unsigned int map_Col_Origin;    // Columns position on the map

    unsigned int data_size;         // Size of all the pixel data

    void *pixels;                   // Pointer to the pixel data that makes up the satalite fragment

    //vector<vector<char>> dat_list;  // 2D vector to store the data fragment

    unsigned int map_index;         // Index of the map which this satalite belongs to

} Satalite;

Satalite dat_to_satalite(string dat_name_file);


#endif