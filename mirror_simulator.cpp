#include "mirror_simulator.h"

MirrorSimulator::MirrorSimulator(){}

MirrorSimulator::MirrorSimulator(int width, int height, double population_density, int output_type)
: AbstractSimulator(width, height, population_density, output_type){}

MirrorSimulator::MirrorSimulator(int width, int height, string user_flatfile, int output_type)
: AbstractSimulator(width, height, user_flatfile, output_type){}


int MirrorSimulator::CountTopLeftCorner(){
  int count = 0;
  if (current_generation_[0][0] == 'X'){
    count += 3;
  } if (current_generation_[0][1] == 'X'){
    count += 2;
  } if (current_generation_[1][0] == 'X'){
    count += 2;
  } if (current_generation_[1][1] == 'X'){
    count ++;
  }
  return count;
}

int MirrorSimulator::CountTopRightCorner(){
  int count = 0;
  if (current_generation_[0][width_ - 1] == 'X'){
    count += 3;
  } if (current_generation_[0][width_ - 2] == 'X'){
    count += 2;
  } if (current_generation_[1][width_ - 1] == 'X'){
    count += 2;
  } if (current_generation_[1][width_ - 2] == 'X'){
    count ++;
  }
  return count;
}

int MirrorSimulator::CountBottomLeftCorner(){
  int count = 0;
  if (current_generation_[height_ - 1][0] == 'X'){
    count += 3;
  } if (current_generation_[height_ - 2][0] == 'X'){
    count += 2;
  } if (current_generation_[height_ - 1][1] == 'X'){
    count += 2;
  } if (current_generation_[height_ - 2][1] == 'X'){
    count ++;
  }
  return count;
}

int MirrorSimulator::CountBottomRightCorner(){
  int count = 0;
  if (current_generation_[height_ - 1][width_ - 1] == 'X'){
    count += 3;
  } if (current_generation_[height_ - 1][width_ - 2] == 'X'){
    count += 2;
  } if (current_generation_[height_ - 2][width_ - 1] == 'X'){
    count += 2;
  } if (current_generation_[height_ - 2][width_ - 2] == 'X'){
    count ++;
  }
  return count;
}

int MirrorSimulator::CountTopRow(int y){
  int count = 0;
  if (current_generation_[0][y - 1] == 'X'){
    count += 2;
  } if (current_generation_[0][y] == 'X'){
    count ++;
  } if (current_generation_[0][y + 1] == 'X'){
    count += 2;
  } if (current_generation_[1][y - 1] == 'X'){
    count ++;
  } if (current_generation_[1][y] == 'X'){
    count ++;
  } if (current_generation_[1][y + 1] == 'X'){
    count ++;
  }
  return count;
}

int MirrorSimulator::CountBottomRow(int y){
  int count = 0;
  if (current_generation_[height_ - 1][y - 1] == 'X'){
    count += 2;
  } if (current_generation_[height_ - 1][y] == 'X'){
    count ++;
  } if (current_generation_[height_ - 1][y + 1] == 'X'){
    count += 2;
  } if (current_generation_[height_ - 2][y - 1] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][y] == 'X'){
    count ++;
  } if (current_generation_[height_ - 2][y + 1] == 'X'){
    count ++;
  }
  return count;
}

int MirrorSimulator::CountLeftColumn(int x){
  int count = 0;
  if (current_generation_[x - 1][0] == 'X'){
    count += 2;
  } if (current_generation_[x][0] == 'X'){
    count ++;
  } if (current_generation_[x + 1][0] == 'X'){
    count += 2;
  } if (current_generation_[x - 1][1] == 'X'){
    count ++;
  } if (current_generation_[x][1] == 'X'){
    count ++;
  } if (current_generation_[x + 1][1] == 'X'){
    count ++;
  }
  return count;
}

int MirrorSimulator::CountRightColumn(int x){
  int count = 0;
  if (current_generation_[x - 1][width_ - 1] == 'X'){
    count += 2;
  } if (current_generation_[x][width_ - 1] == 'X'){
    count ++;
  } if (current_generation_[x + 1][width_ - 1] == 'X'){
    count += 2;
  } if (current_generation_[x - 1][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[x][width_ - 2] == 'X'){
    count ++;
  } if (current_generation_[x + 1][width_ - 2] == 'X'){
    count ++;
  }
  return count;
}
