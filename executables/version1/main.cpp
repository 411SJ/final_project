// =========================================================
///  Name:       Sourivong Thepsimoung & Jacob Hampton
/// Professor:  Jean Herve
///  Course:     CSC 412 Operating System
///  Program:    Main.cpp
// ==========================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
//
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//
#include "Satalite.h"
#include "Map.h"


using namespace std;

// ==========================================================
///                      Prototypes
// ==========================================================
void print_dat_file(Satalite dat_list);

// ==========================================================
///                      Helper Functions
// ==========================================================
/*
void print_dat_file(Satalite dat_file)
{
    for (vector<char> &temp_vector : dat_file.dat_list)
    {
        for (char &c : temp_vector)
        {
            std::cout << c;
        }
        cout << '\n';
    }
}
*/
// ==========================================================
///                      Main Program
// ==========================================================
int main(int argc, char *argv[])
{

    // storing standard inputs into variables
    string watch_folder = argv[1];
    string output_folder = argv[2];
    int numMaps = atoi(argv[3]);
    Map image_list;
    Map temp_map;
    file_name file_struct;

    // checks if the number of maps has its own width
    // and height included from the standard input
    if (argc < (numMaps * 2) + 2)
    {
        cout << "Usage. Not enough arguments passed." << endl;
    }
    else if (argc > (numMaps * 2) + 4)
    {
        cout << "Usage. Too many arguments passed." << endl;
    }
    else
    {
        // must be replace by another directory using script
        //string input("/home/kevin/Desktop/final_project-main/set_1/DataSet_1/.");
        string input("/home/jacobhampton/Documents/final_project/set_1/DataSet_1/");
        file_struct = Listdir(input, file_struct);
        cout << "File struct made" << endl;
        // reads the file and throws the satalie images into the Map Structure
        for (vector<toString>::iterator node = file_struct.my_file.begin() + 2; node != file_struct.my_file.end(); ++node)
        {
            //cout << node->s << endl;
            string file = "/home/jacobhampton/Documents/final_project/set_1/DataSet_1/" + node->s;
            //cout << file <<endl;
            if(file.length() > input.length()+3){
                image_list = dat_reader(image_list, file);
            }
            
        }

        temp_map = map_sort(image_list, 1);
        create_image(temp_map);
        cout << "Image Created" << endl;
        map_to_TGA(temp_map, output_folder);
        // prints the satalite vector
        // print_dat_file(image_list.Map_list.at(0));
        cout << "we are here." << endl;
    }

    return 0;
}
