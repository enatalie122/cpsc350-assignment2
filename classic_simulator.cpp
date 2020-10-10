/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

classic_simulator.cpp is the implementation file for the ClassicSimulator class.
*/

#include "classic_simulator.h"

ClassicSimulator::ClassicSimulator(){}

ClassicSimulator::ClassicSimulator(int width, int height, double population_density, int output_type)
: AbstractSimulator(width, height, population_density, output_type){}

ClassicSimulator::ClassicSimulator(int width, int height, string user_flatfile, int output_type)
: AbstractSimulator(width, height, user_flatfile, output_type){}

int ClassicSimulator::CountTopLeftCorner(){
  int count = 0;
  if (current_generation_[0][1] == 'X'){
    count ++;
  } if (current_generation_[1][0] == 'X'){
    count ++;
  } if (current_generation_[1][1] == 'X'){
    count ++;
  }
  return count;
}

int ClassicSimulator::CountTopRightCorner(){
  int count = 0;
  if (current_generation_[0][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[1][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[1][width_ - 1] == 'X'){
    count ++;
  }
  return count;
}

int ClassicSimulator::CountBottomLeftCorner(){
  int count = 0;
  if (current_generation_[height_ - 2][0] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][1] == 'X'){
    count ++;
  }
  return count;
}

int ClassicSimulator::CountBottomRightCorner(){
  int count = 0;
  if (current_generation_[height_ - 1][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][width_ - 1] == 'X'){
    count ++;
  }
  return count;
}

int ClassicSimulator::CountTopRow(int y){
  int count = 0;
  if (current_generation_[0][y - 1] == 'X'){
    count ++;
  } if (current_generation_[1][y - 1] == 'X'){
    count++;
  } if (current_generation_[1][y] == 'X'){
    count++;
  } if (current_generation_[1][y + 1] == 'X'){
    count++;
  } if (current_generation_[0][y + 1] == 'X'){
    count++;
  }
  return count;
}

int ClassicSimulator::CountBottomRow(int y){
  int count = 0;
  if (current_generation_[height_ - 1][y - 1] == 'X'){
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

int ClassicSimulator::CountLeftColumn(int x){
  int count = 0;
  if (current_generation_[x - 1][0] == 'X'){
    count ++;
  } if (current_generation_[x - 1][1] == 'X'){
    count ++;
  } if (current_generation_[x][1] == 'X'){
    count ++;
  } if (current_generation_[x + 1][1] == 'X'){
    count ++;
  } if (current_generation_[x + 1][0] == 'X'){
    count ++;
  }
  return count;
}

int ClassicSimulator::CountRightColumn(int x){
  int count = 0;
  if (current_generation_[x - 1][width_ - 1] == 'X'){
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
