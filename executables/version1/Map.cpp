// =========================================================
///  Name:       Sourivong Thepsimoung & Jacob Hampton
///  Professor:  Jean Herve
///  Course:     CSC 412 Operating System
///  Program:    Map.cpp
// ==========================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
# include <cstdio>
# include <cstdlib>
# include <cstring>
//
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
//
#include "Satalite.h"
#include "Map.h"
#include "Pixel.h"

using namespace std;

// =========================================================
///  Reads the .dat extension file and imports all the data
///  into a Satalite Struct and then into the Map Struct
// ==========================================================
Map dat_reader(Map image_list, string dat_name_file)
{
    //cout << dat_name_file << endl;
    Satalite sata;
    sata = dat_to_satalite(dat_name_file);
    image_list.Map_list.push_back(sata);
    return image_list;
}

// =========================================================
///  Loops through the data set folder. take all of the file
///  and store into a vector of strings for future directory
// ==========================================================
file_name Listdir(const string &path, file_name file_struct)
{
    struct dirent *entry;
    DIR *dp;
    dp = ::opendir(path.c_str());
    if (dp == NULL)
    {
        perror("opendir; Path does not exist or could not be read");
        return file_struct;
    }
    while ((entry = ::readdir(dp)))
    {
        toString s;
        //cout << entry -> d_name << endl;
        s.s = entry->d_name;
        file_struct.my_file.push_back(s);
    }
    ::closedir(dp);
    return file_struct;
}

// =========================================================
///  loops through the data fragment structs and inputs all
///  values with inputted idx into its own map structure
// ==========================================================
Map map_sort(Map image_list, unsigned int image_number)
{
    Map temp_map;
    for (vector<Satalite>::iterator dat = image_list.Map_list.begin(); dat != image_list.Map_list.end(); dat++)
    {
        if (image_number == dat->map_index)
        {
            temp_map.Map_list.push_back(*dat);
        }
    }
    return temp_map;
}

// =========================================================
///  creates the image after the map is sorted by indexes.
///  positions the fragments into the correct spots.
// ==========================================================
void create_image(Map map)
{
    for (vector<Satalite>::iterator dat = map.Map_list.begin(); dat != map.Map_list.end(); dat++)
    {
        unsigned int current_row = dat->map_Row_Origin;
        unsigned int current_col = dat->map_Col_Origin;
        for (vector<Pixel> &temp_vector : dat->dat_list)
        {
            if (current_row <= map.height)
            {
                for (Pixel &pix : temp_vector)
                {
                    
                    cout << "Row: " << current_row << " Col: " << current_col << endl;
                    if (current_col <= map.width)
                    {
                        cout << "Col is valid so is row " << endl;
                        cout << "R: " << pix.r << " G: " << pix.g <<" B: "<<pix.b<< endl;
                        /*
                        Pixel temp = map.image.at(current_row).at(current_col);
                        if (temp.status == OFF)
                        {
                            map.image.at(current_row).at(current_col) = pix;
                        }
                        else
                        {
                            map.image.at(current_row).at(current_col) = average_pixel(pix, temp);
                        }
                        */
                        map.image.at(current_row).at(current_col) = pix;
                    }
                    current_col++;
                }
            }
            current_row++;
        }
    }
}

// =========================================================
///  creates a TGA file from the given map.
///  places it into the output folder.
// ==========================================================
void map_to_TGA(Map map, string output_path)
{
    //--------------------------------
    // open TARGA output file
    //--------------------------------

    FILE* tga_out = fopen(output_path.c_str(), "wb" );
	if (tga_out == NULL)
	{
		printf("Cannot create image file %s \n", output_path.c_str());
		exit(1);
	}

    //--------------------------------
    // create the header (TARGA file)
    //--------------------------------
    char head[18];
    head[0] = 0;                       // ID field length.
    head[1] = 0;                       // Color map type.
    head[2] = 2;                       // Image type: true color, uncompressed.
    head[3] = head[4] = 0;             // First color map entry.
    head[5] = head[6] = 0;             // Color map length.
    head[7] = 0;                       // Color map entry size.
    head[8] = head[9] = 0;             // Image X origin.
    head[10] = head[11] = 0;           // Image Y origin.
    head[13] = (char)(map.width >> 8); // Image width.
    head[12] = (char)(map.width & 0x0FF);
    head[15] = (char)(map.height >> 8); // Image height.
    head[14] = (char)(map.height & 0x0FF);
    head[16] = 24; // Bits per pixel.
    head[17] = 0;  // Image descriptor bits ;

    fwrite(head, sizeof(char), 18, tga_out);

    //unsigned char* data  = (unsigned char*) raster;
    for (unsigned short i = 0; i < map.height; i++)
    {
        unsigned long offset = i * 4 * map.width;
        for (unsigned short j = 0; j < map.width; j++)
        {
            fwrite(&map.image.at(j).at(i).b, sizeof(char), 1, tga_out);
            fwrite(&map.image.at(j).at(i).g, sizeof(char), 1, tga_out);
            fwrite(&map.image.at(j).at(i).r, sizeof(char), 1, tga_out);
            offset += 4;
        }
    }
    fclose(tga_out);
}

