/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

abstract_simulator.h is the header file for the AbstractSimulator class.
*/

#ifndef ABSTRACT_SIMULATOR_H
#define ABSTRACT_SIMULATOR_H

#include <string>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include "file.h"

using namespace std;

//The AbstractSimulator class is an abstract class for the different game modes for the Game of Life.
class AbstractSimulator{

public:
  /*Default constructor: AbstractSimulator
  Sets int values to 0, the can_simulate_ boolean to true, and declares the current_generation_ array.
  */
  AbstractSimulator();
  /*Overloaded constructor: AbstractSimulator
  Parameters:
    width: an int representing the number of columns of the grid
    height: an int representing the number of rows of the grid
    population_density: a double representing the population density of the starting generation
    output_type: an int representing which type of output the user chooses
  */
  explicit AbstractSimulator(int width, int height, double population_density, int output_type);
  /*Overloaded constructor: AbstractSimulator
  Parameters:
    width: an int representing the number of columns of the grid
    height: an int representing the number of rows of the grid
    user_flatfile: a string representing the starting generation for a Game of Life.
    output_type: an int representing which type of output the user chooses
  */
  explicit AbstractSimulator(int width, int height, string user_flatfile, int output_type);
  //Destructor: ~AbstractSimulator
  ~AbstractSimulator();
  //Simulate
  void Simulate();

protected:
  //DeclareArray
  void DeclareArray();
  //InitializeArray
  void InitializeArray();
  //GenerateRandomArray
  void GenerateRandomArray();
  /*GenerateRandomNumber
  Parameters:
    val: an int representing the range from which to produce a random number
  Returns a random int.
  */
  int GenerateRandomNumber(int val);
  /*CountOccupiedSpots
  Returns an int representing the number of spots currently occupied in current_generation_.
  */
  int CountOccupiedSpots();

  //PrintArray
  void PrintArray();
  /*CanSimulate
  Parameters:
    next_generation: a double pointer to an array of chars representing the next generation in the Game of Life
  */
  void CanSimulate(char ** next_generation);
  //ConstructUserArray
  void ConstructUserArray();
  //Generate
  void Generate();
  /*CountNeighbors
  Parameters:
    x: an int representing the row of the current cell being evaluated
    y: an int representing the column of the current cell being evaluated
  Returns an int representing the number of neighbors of a given cell.
  */
  int CountNeighbors(int x, int y);
  /*GenerateNewTile
  Parameters:
    neighbors: an int representing the number of neighbors of a given cell
    currFill: a char that represents whether or not a cell is currently filled
  Returns a char that represents whether or not a cell will be filled in the next generation
  */
  char GenerateNewTile(int neighbors, char currFill);
  /*UpdateArray
  Parameters:
    new_generation: a double pointer to an array of chars representing the next generation of cells
  */
  void UpdateArray(char ** new_generation);
  /*CountMiddleTiles
  Parameters:
    x: an int representing the row of the current cell being evaluated
    y: an int representing the column of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell.
  */
  int CountMiddleTiles(int x, int y);

  /*CountTopLeftCorner
  Returns an int representing the number of neighbors for the cell in the top left corner.
  */
  virtual int CountTopLeftCorner() = 0;
  /*CountTopRightCorner
  Returns an int representing the number of neighbors for the cell in the top right corner.
  */
  virtual int CountTopRightCorner() = 0;
  /*CountBottomLeftCorner
  Returns an int representing the number of neighbors for the cell in the bottom left corner.
  */
  virtual int CountBottomLeftCorner() = 0;
  /*CountBottomRightCorner
  Returns an int representing the number of neighbors for the cell in the bottom right corner.
  */
  virtual int CountBottomRightCorner() = 0;
  /*CountTopRow
  Parameters:
    y: an int representing the column of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell in the top row.
  */
  virtual int CountTopRow(int y) = 0;
  /*CountBottomRow
  Parameters:
    y: an int representing the column of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell in the bottom row.
  */
  virtual int CountBottomRow(int y) = 0;
  /*CountLeftColumn
  Parameters:
    x: an int representing the row of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell in the left column.
  */
  virtual int CountLeftColumn(int x) = 0;
  /*CountRightColumn
  Parameters:
    x: an int representing the row of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell in the right column.
  */
  virtual int CountRightColumn(int x) = 0;

  /*width_
  An int representing the number of the columns in the grid.
  */
  int width_;
  /*height_
  An int representing the number of the rows in the grid.
  */
  int height_;
  /*user_flatfile_
  A string representing the starting generation for a Game of Life.
  */
  string user_flatfile_;
  /*current_generation_
  A double pointer to an array of chars representing the current generation in the Game of Life.
  */
  char ** current_generation_;
  /*can_simulate_
  A boolean representing whether or not the simulation has stabilized.
  */
  bool can_simulate_;
  /*output_type_
  An int representing which type of output the user chooses.
  */
  int output_type_;
  /*generation_counter_
  An int representing the number of the current generation.
  */
  int generation_counter_;
  /*population_density_
  A double representing the population density of the starting generation.
  */
  double population_density_;

};

#endif
