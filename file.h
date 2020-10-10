/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

file.h is the header file for the File class.
*/

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;


//The File class reads and writes files.
class File{

public:
  /*Default constructor: File
  Constructs empty strings and sets integer values to 0.
  */
  File();
  //Destructor: ~File
  ~File();

  /*Accessor: get_user_flatfile
  Returns a string representing the starting generation for a Game of Life.
  */
  string get_user_flatfile();
  /*Accessor: get_height
  Returns an int representing the number of rows in a user-specified grid.
  */
  int get_height();
  /*Accessor: get_width
  Returns an int representing the number of columns in a user-specified grid.
  */
  int get_width();
  /*Mutator: set_file_name
  Parameters:
    file_name: a string representing the name of a file
  */
  void set_file_name(string file_name);

  //ReadFile
  void ReadFile();
  /*WriteToFile
  Parameters:
    generation_number: an int representing the current generation number
    current_generation: a double pointer to an array of chars representing the cells of the current generation
    width: an int representing the number of columns in a grid
    height: an int representing the number of rows in a grid
  */
  void WriteToFile(int generation_number, char ** current_generation, int width, int height);

private:
  /*file_name_
  A string representing the name of a file.
  */
  string file_name_;
  /*width_
  An int representing the number of columns in a grid.
  */
  int width_;
  /*height_
  An int representing the number of rows in a grid.
  */
  int height_;
  /*user_flatfile_
  A string representing the starting generation for a Game of Life.
  */
  string user_flatfile_;

};

#endif
