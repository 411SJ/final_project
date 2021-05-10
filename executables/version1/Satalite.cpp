// =========================================================
//  Name:       Sourivong Thepsimoung & Jacob Hampton
//  Professor:  Jean Herve
//  Course:     CSC 412 Operating System 
//  Program:    satalite.cpp
// ==========================================================
#include <string>
#include <iostream>
#include <fstream>
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

        for (char &c : line)
        {
            temp_vector.push_back(c);
        }
        dat_struct.dat_list.push_back(temp_vector);
    }

    image_list.Map_list.push_back(dat_struct);
    return image_list;
}