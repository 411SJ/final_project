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
//#include <bits/stdc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Satalite.h"


// =========================================================
//  Reads the .dat extension file and imports all the data 
//  into a Satalite Struct and then into the Map Struct
// ==========================================================
Satalite dat_to_satalite(string dat_name_file)
{
    Satalite satalite;
    unsigned int idx, data_value1, data_value2, data_value3, data_value4;

    string line;
    ifstream infile(dat_name_file);
    while (getline(infile, line))
    {
        infile >> idx >> data_value1 >> data_value2 >> data_value3 >> data_value4;
        satalite.map_index = idx;
        satalite.map_Row_Origin = data_value1;
        satalite.map_Col_Origin = data_value2;
        satalite.height = data_value3;
        satalite.width =data_value4;
        
        

        vector<char> temp_vector;
        unsigned char* the_data;
        the_data = (unsigned char*) malloc(satalite.width*satalite.height*5);
        unsigned char* dest = the_data;
        for (unsigned short i=0; i<satalite.height; i++)
        {
            unsigned long offset = i*5*satalite.width;
            for (unsigned short j=0; j<satalite.height; j++)
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
        /*
        for (char &c : line)
        {
            temp_vector.push_back(c);
        }
        satalite.dat_list.push_back(temp_vector);
        */
    }
    //image_list.Map_list.push_back(dat_struct);
    return satalite;
}