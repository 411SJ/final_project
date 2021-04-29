// =========================================================
//  Name:       Sourivong Thepsimoung & Jacob Hampton
//  Professor:  Jean Herve
//  Course:     CSC 412 Operating System
//  Program:    Map.h
// ==========================================================

#ifndef MAP_H
#define MAP_H
using namespace std;

#include <vector>
//
#include "Satalite.h"

using namespace std;

const unsigned char VALID = 1;
const unsigned char NOT_VALID = 0;


// ==========================================================
//                      Structures
// ==========================================================

typedef struct Map
{
    unsigned width;
    unsigned height;
    vector<Satalite> Map_list;
} Map;


typedef struct toString
{
    string s;
} toString;


typedef struct file_names
{
    vector<toString> my_file;
} file_name;

typedef struct Map_collection{
    int numMaps;
    vector<Map> Map_Vector;

}Map_collection;

// ==========================================================
//                      Prototypes
// ==========================================================

Map dat_reader(Map image_list, string dat_name_file);
file_name Listdir(const string &path, file_name file_struct);
Map map_sort(Map image_list, unsigned int image_number);

#endif