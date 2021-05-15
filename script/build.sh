#!/bin/bash

cd ..
ls
cd executables/version1/
cd .

file1="output"
file2="watch"
if [[ ! -f $file1 ]] && [[  ! -f $file2 ]]
then
    mkdir watch
    mkdir output
fi

FILE_OUTPUT="executables/version1/output/"
FILE_WATCH="executables/version1/watch"

g++ -std=c++14 -Wall -Wextra -o main main.cpp Map.cpp Satalite.cpp tasks.cpp Pixel.cpp
./main executables/version1/watch /home/kevin/Desktop/final_project-main/executables/version1/output/export.tga 3 300 450 200 320 400 480
