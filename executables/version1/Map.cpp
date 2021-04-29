// =========================================================
//  Name:       Sourivong Thepsimoung & Jacob Hampton
//  Professor:  Jean Herve
//  Course:     CSC 412 Operating System
//  Program:    Main.cpp
// ==========================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
//
#include "Satalite.h"
#include "Map.h"

using namespace std;


// =========================================================
//  Reads the .dat extension file and imports all the data 
//  into a Satalite Struct and then into the Map Struct
// ==========================================================
Map dat_reader(Map image_list, string dat_name_file)
{
    Satalite dat_struct;
    unsigned int idx, data_value1, data_value2, data_value3, data_value4;

    string line;
    ifstream infile(dat_name_file);
    while (getline(infile, line))
    {
        infile >> idx >> data_value1 >> data_value2 >> data_value3 >> data_value4;
        dat_struct.image_selection = idx;
        dat_struct.width = data_value1;
        dat_struct.height = data_value2;
        
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


// =========================================================
//  Loops through the data set folder. take all of the file
//  and store into a vector of strings for future directory
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

Map map_sort(Map image_list, unsigned int image_number){
    Map temp_map;
    for (vector<Satalite>::iterator dat = image_list.Map_list.begin(); dat != image_list.Map_list.end(); dat++){
        if(image_number == dat->image_selection){
            temp_map.Map_list.push_back(*dat);
        }
    }
    return temp_map;
}