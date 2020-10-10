/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

file.cpp is the implementation file for the File class.
*/

#include "file.h"

File::File(){
  string file_name_ = "";
  int width_ = 0;
  int height_ = 0;
  string user_flatfile_ = "";
}

File::~File(){}

int File::get_height(){
  return height_;
}

int File::get_width(){
  return width_;
}

string File::get_user_flatfile(){
  return user_flatfile_;
}

void File::set_file_name(string file_name){
  file_name_ = file_name;
}

void File::ReadFile(){
  int line_number = 0;
  int row_number = 0;
  string line;
  ifstream file;
  while (file.is_open() == false){
    file.open(file_name_);
    if (file.is_open()){
      while (getline (file, line)){
        if (line_number == 0){
          height_ = stoi(line);
        } else if (line_number == 1){
          width_ = stoi(line);
        } else {
          for(int i = 0; i < line.length() - 1; ++ i){
            user_flatfile_.push_back(line.at(i));
          }
          row_number++;
        }
        line_number++;
      }
      file.close();
      break;
    } else {
      cout << "Unable to open file." << endl;
      cout << "Enter a file name: ";
      cin >> file_name_;
      cout << endl;
    }
  }
}

void File::WriteToFile(int generation_number, char ** current_generation, int width, int height){
  ofstream my_file;
  while (my_file.is_open() == false){
    my_file.open(file_name_, ios::in | ios::out | ios::app);
    if (my_file.is_open()){
      my_file << generation_number << endl;
      for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
          my_file << current_generation[i][j];
        } my_file << endl;
      } my_file << endl;
      my_file.close();
      break;
    } else {
      cout << "unable to open file" << endl;
      cout << "Enter a file name: ";
      cin >> file_name_;
      cout << endl;
    }
  }
}
