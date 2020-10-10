/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

doughnut_simulator.cpp is the implementation file for the DoughnutSimulator class.
*/

#include "doughnut_simulator.h"

DoughnutSimulator::DoughnutSimulator(){}

DoughnutSimulator::DoughnutSimulator(int width, int height, double population_density, int output_type)
: AbstractSimulator(width, height, population_density, output_type){}

DoughnutSimulator::DoughnutSimulator(int width, int height, string user_flatfile, int output_type)
: AbstractSimulator(width, height, user_flatfile, output_type){}


int DoughnutSimulator::CountTopLeftCorner(){
  int count = 0;
  if (current_generation_[0][1] == 'X'){
    count ++;
  } if (current_generation_[1][1] == 'X'){
    count ++;
  } if (current_generation_[1][0] == 'X'){
    count ++;
  } if (current_generation_[0][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[1][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][0] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][width_ - 1] == 'X'){
    count ++;
  }
  return count;
}

int DoughnutSimulator::CountTopRightCorner(){
  int count = 0;
  if (current_generation_[0][0] == 'X'){
    count ++;
  } if (current_generation_[1][0] == 'X'){
    count ++;
  } if (current_generation_[0][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[1][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[1][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][0] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][width_ - 1] == 'X'){
    count ++;
  }
  return count;
}

int DoughnutSimulator::CountBottomLeftCorner(){
  int count = 0;
  if (current_generation_[0][0] == 'X'){
    count ++;
  } if (current_generation_[0][1] == 'X'){
    count ++;
  } if (current_generation_[0][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][0] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][width_ - 1] == 'X'){
    count ++;
  }
  return count;
}

int DoughnutSimulator::CountBottomRightCorner(){
  int count = 0;
  if (current_generation_[0][0] == 'X'){
    count ++;
  } if (current_generation_[0][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[0][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][0] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][0] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][width_ - 1] == 'X'){
    count ++;
  }
  return count;
}

int DoughnutSimulator::CountTopRow(int y){
  int count = 0;
  if (current_generation_[0][y - 1] == 'X'){
    count ++;
  } if (current_generation_[0][y + 1] == 'X'){
    count ++;
  } if (current_generation_[1][y - 1] == 'X'){
    count ++;
  } if (current_generation_[1][y] == 'X'){
    count ++;
  } if (current_generation_[1][y + 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][y - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][y] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][y + 1] == 'X'){
    count ++;
  }
  return count;
}

int DoughnutSimulator::CountBottomRow(int y){
  int count = 0;
  if (current_generation_[0][y - 1] == 'X'){
    count ++;
  } if (current_generation_[0][y] == 'X'){
    count ++;
  } if (current_generation_[0][y + 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][y - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][y - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][y] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][y + 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][y + 1] == 'X'){
    count ++;
  }
  return count;
}

int DoughnutSimulator::CountLeftColumn(int x){
  int count = 0;
  if (current_generation_[x - 1][0] == 'X'){
    count ++;
  } if (current_generation_[x - 1][1] == 'X'){
    count ++;
  } if (current_generation_[x][1] == 'X'){
    count ++;
  } if (current_generation_[x + 1][0] == 'X'){
    count ++;
  } if (current_generation_[x + 1][1] == 'X'){
    count ++;
  } if (current_generation_[x - 1][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[x][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[x + 1][width_ - 1] == 'X'){
    count ++;
  }
  return count;
}

int DoughnutSimulator::CountRightColumn(int x){
  int count = 0;
  if (current_generation_[x - 1][0] == 'X'){
    count ++;
  } if (current_generation_[x][0] == 'X'){
    count ++;
  } if (current_generation_[x + 1][0] == 'X'){
    count ++;
  } if (current_generation_[x - 1][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[x - 1][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[x][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[x + 1][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[x + 1][width_ - 1] == 'X'){
    count ++;
  }
  return count;
}
