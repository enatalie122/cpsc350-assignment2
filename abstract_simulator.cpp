/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

abstract_simulator.cpp is the implementation file for the AbstractSimulator class.
*/

#include "abstract_simulator.h"

AbstractSimulator::AbstractSimulator(){
  width_ = 0;
  height_ = 0;
  can_simulate_ = true;
  output_type_ = 0;
  generation_counter_ = 0;
  DeclareArray();
  InitializeArray();
}

AbstractSimulator::AbstractSimulator(int width, int height, double population_density, int output_type){
  width_ = width;
  height_ = height;
  can_simulate_ = true;
  output_type_ = output_type;
  generation_counter_ = 0;
  population_density_ = population_density;
  DeclareArray();
  GenerateRandomArray();
}

AbstractSimulator::AbstractSimulator(int width, int height, string user_flatfile, int output_type){
  width_ = width;
  height_ = height;
  user_flatfile_ = user_flatfile;
  can_simulate_ = true;
  output_type_ = output_type;
  generation_counter_ = 0;
  DeclareArray();
  ConstructUserArray();
}

AbstractSimulator::~AbstractSimulator(){
  delete current_generation_;
}


void AbstractSimulator::Simulate(){
  File *fw = new File();
  if (output_type_ == 2){
    cout << "Press enter to start." << endl;
  }
  while(can_simulate_ == true){
    if (generation_counter_ > 1){
      Generate();
    }
    if (can_simulate_ == false){
      cout << "Simulation has stabilized, press enter to exit program." << endl;
      if (output_type_ == 3){
        cin.ignore();
      }
      cin.get();
      break;
    }
    if (output_type_ == 1){
      sleep(1);
      PrintArray();
    } else if (output_type_ == 2){
      cin.get();
      PrintArray();
    } else if (output_type_ == 3){
      if (generation_counter_ == 0){
        string name;
        cout << "Enter a file name: " << endl;
        cin >> name;
        fw -> set_file_name(name);
      }
      fw -> WriteToFile(generation_counter_, current_generation_, width_, height_);
    }
    generation_counter_++;
  }
  delete fw;
}


void AbstractSimulator::DeclareArray(){
  current_generation_ = new char*[height_];
  for (int i = 0; i < height_; ++i) {
    current_generation_[i] = new char[width_];
  }
}

void AbstractSimulator::InitializeArray(){
  for (int i = 0; i < height_; ++i){
    for (int j = 0; j < width_; ++j){
      current_generation_[i][j] = '-';
    }
  }
}

void AbstractSimulator::GenerateRandomArray(){
  InitializeArray();
  srand(time(0));
  int relative_density = population_density_ * (width_ * height_);
  int population_counter = 0;

  while(population_counter != relative_density){
    int x = GenerateRandomNumber(height_);
    int y = GenerateRandomNumber(width_);
    current_generation_[x][y] = 'X';
    population_counter = CountOccupiedSpots();
  }
}

int AbstractSimulator::GenerateRandomNumber(int val){
  int location = rand()%val;
  return location;
}

int AbstractSimulator::CountOccupiedSpots(){
  int count = 0;
  for(int i = 0; i < height_; ++ i){
    for (int j = 0; j < width_; ++j){
      if(current_generation_[i][j] == 'X'){
        count++;
      }
    }
  }
  return count;
}


void AbstractSimulator::ConstructUserArray(){
  int string_index = 0;
  for (int i = 0; i < height_; ++i){
    for (int j = 0; j < width_; ++j){
      current_generation_[i][j] = user_flatfile_.at(string_index);
      string_index++;
    }
  }
}


void AbstractSimulator::Generate(){
  char ** temp_array;
  temp_array = new char*[height_];
  for (int i = 0; i < height_; ++i) {
    temp_array[i] = new char[width_];
  }
  for(int i = 0; i < height_; ++i) {
    for(int j = 0; j < width_; ++j) {
      int neighbor_count = CountNeighbors(i, j);
      temp_array[i][j] = GenerateNewTile(neighbor_count, current_generation_[i][j]);
    }
  }
  CanSimulate(temp_array);
  UpdateArray(temp_array);
  delete temp_array;
}

void AbstractSimulator::PrintArray(){
  if (generation_counter_ == 0){
    cout << 0 << endl;
  } else {
    cout << "generation " << generation_counter_ << endl;
  }
  for (int i = 0; i < height_; ++i){
    for(int j = 0; j < width_; ++j){
      cout << current_generation_[i][j];
    } cout << endl;
  } cout << endl;
}

void AbstractSimulator::CanSimulate(char ** next_generation){
  int cell_count = 0;
  int empty_count = 0;
  for(int i = 0; i < height_; ++i) {
    for(int j = 0; j < width_; ++j) {
      if(next_generation[i][j] == current_generation_[i][j]){
        cell_count++;
      }
      if (next_generation[i][j] == '-'){
        empty_count++;
      }
    }
  }
  if(cell_count == (height_ * width_) || empty_count == (height_ * width_)){
    can_simulate_ = false;
  }
}

void AbstractSimulator::UpdateArray(char ** new_generation){
  for (int i = 0; i < height_; ++i){
    for (int j = 0; j < width_; ++ j){
      current_generation_[i][j] = new_generation[i][j];
    }
  }
}

int AbstractSimulator::CountNeighbors(int x, int y){
  int neighbor_count = 0;
  if(x == 0 && y == 0){
    neighbor_count = CountTopLeftCorner();
  } else if (x == 0 && y == (width_ - 1)){
    neighbor_count = CountTopRightCorner();
  } else if (x == (height_ - 1) && y == 0){
    neighbor_count = CountBottomLeftCorner();
  } else if (x == (height_ - 1) && y == (width_ - 1)){
    neighbor_count = CountBottomRightCorner();
  } else if (x == 0){
    neighbor_count = CountTopRow(y);
  } else if (x == (height_ - 1)){
    neighbor_count = CountBottomRow(y);
  } else if (y == 0){
    neighbor_count = CountLeftColumn(x);
  } else if (y == (width_ - 1)){
    neighbor_count = CountRightColumn(x);
  } else {
    neighbor_count = CountMiddleTiles(x, y);
  }
  return neighbor_count;
}

char AbstractSimulator::GenerateNewTile(int neighbors, char currFill){
  char next_generation;
  if (neighbors <= 1){
    next_generation = '-';
  } else if (neighbors == 2){
    if (currFill == 'X'){
      next_generation = 'X';
    } else if (currFill == '-'){
      next_generation = '-';
    }
  } else if (neighbors == 3){
    next_generation = 'X';
  } else if (neighbors >= 4){
    next_generation = '-';
  }
  return next_generation;
}

int AbstractSimulator::CountMiddleTiles(int x, int y){
  int count = 0;
  if (current_generation_[x - 1][y - 1] == 'X'){
    count ++;
  } if (current_generation_[x - 1][y] == 'X'){
    count ++;
  } if (current_generation_[x - 1][y + 1] == 'X'){
    count ++;
  } if (current_generation_[x][y - 1] == 'X'){
    count ++;
  } if (current_generation_[x][y + 1] == 'X'){
    count ++;
  } if (current_generation_[x + 1][y - 1] == 'X'){
    count ++;
  } if (current_generation_[x + 1][y] == 'X'){
    count ++;
  } if (current_generation_[x + 1][y + 1] == 'X'){
    count ++;
  }
  return count;
}
