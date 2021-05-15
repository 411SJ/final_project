// =========================================================
//  Name:       Sourivong Thepsimoung & Jacob Hampton
//  Professor:  Jean Herve
//  Course:     CSC 412 Operating System
//  Program:    satalite.cpp
// ==========================================================
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Satalite.h"
#include "Pixel.h"

using namespace std;

// =========================================================
//
//
// ==========================================================
Satalite dat_to_satalite(string dat_name_file)
{
    Satalite satalite;
    unsigned int idx, data_value1, data_value2, data_value3, data_value4;

    string line;
    ifstream infile(dat_name_file);

    infile >> idx >> data_value1 >> data_value2 >> data_value3 >> data_value4;
    satalite.map_index = idx;
    satalite.map_Row_Origin = data_value1;
    satalite.map_Col_Origin = data_value2;
    satalite.height = data_value3;
    satalite.width = data_value4;

    /*
        unsigned char* the_data;
        the_data = (unsigned char*) malloc(satalite.width*satalite.height*5);
        unsigned char* dest = the_data;
        for (unsigned short i=0; i<satalite.height; i++)
        {
            unsigned long offset = i*5*satalite.width;
            for (unsigned short j=0; j<satalite.width; j++)
            {
                //fread(dest, 4*sizeof(char), 1, infile);
                infile >> dest[offset];
                infile >> dest[offset+1];
                infile >> dest[offset+2];
                infile >> dest[offset+3];
                dest+=5;
            }
        }
        satalite.pixels = the_data; 
        */

    // storing values into a 2D vector


    /*
    while(getline(infile, line)){
        vector<char> temp_vector;
        for (char &c : line)
        {
            temp_vector.push_back(c);
        }
        satalite.dat_list.push_back(temp_vector);
    }
    */
    int buff = 0;
    while(getline(infile, line)){
        unsigned char r=0,g=0,b=0;
        vector<Pixel> temp_vector;
        for (char &c : line)
        {
            switch(buff%4){
                case 0:
                    r = c;
                    break;
                case 1:
                    g = c;
                    break;
                case 2:
                    b = c;
                    break;
                case 3:
                    temp_vector.push_back(create_pixel(r,g,b,c));
                    break;
                default:
                //This is impossible
                    break;
            }
            buff++;
        }
        satalite.dat_list.push_back(temp_vector);
    }
    return satalite;
}
/*
// =========================================================
//  creates a TGA file from the given map.
//  places it into the output folder.
// ==========================================================
void map_to_TGA(Satalite sata, string output_path)
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
    head[13] = (char)(sata.width >> 8); // Image width.
    head[12] = (char)(sata.width & 0x0FF);
    head[15] = (char)(sata.height >> 8); // Image height.
    head[14] = (char)(sata.height & 0x0FF);
    head[16] = 24; // Bits per pixel.
    head[17] = 0;  // Image descriptor bits ;

    fwrite(head, sizeof(char), 18, tga_out);

    //unsigned char* data  = (unsigned char*) raster;
    for (unsigned short i = 0; i < sata.height; i++)
    {
        unsigned long offset = i * 4 * satap.width;
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
*/
