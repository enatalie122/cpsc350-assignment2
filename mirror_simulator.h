/*
Natalie Ewing
2313895
ewing@chapman.edu
CPSC 350-01
Assignment 2

mirror_simulator.h is the header file for the MirrorSimulator class.
*/

#ifndef MIRROR_SIMULATOR_H
#define MIRROR_SIMULATOR_H

#include "abstract_simulator.h"

//The MirrorSimulator Class extends from the AbstractSimulator Class, and simulates the Game of Life with mirror mode rules.
class MirrorSimulator : public AbstractSimulator {

public:
  //Default constructor: MirrorSimulator
  MirrorSimulator();
  /*Overloaded constructor: MirrorSimulator
  Parameters:
    width: an int representing the number of columns of the grid
    height: an int representing the number of rows of the grid
    population_density: a double representing the population density of the starting generation
    output_type: an int representing which type of output the user chooses
  */
  MirrorSimulator(int width, int height, double population_density, int output_type);
  /*Overloaded constructor: MirrorSimulator
  Parameters:
    width: an int representing the number of columns of the grid
    height: an int representing the number of rows of the grid
    user_flatfile: a string representing the starting generation for a Game of Life.
    output_type: an int representing which type of output the user chooses
  */
  MirrorSimulator(int width, int height, string user_flatfile, int output_type);

private:
  /*CountTopLeftCorner
  Returns an int representing the number of neighbors for the cell in the top left corner.
  */
  int CountTopLeftCorner();
  /*CountTopRightCorner
  Returns an int representing the number of neighbors for the cell in the top right corner.
  */
  int CountTopRightCorner();
  /*CountBottomLeftCorner
  Returns an int representing the number of neighbors for the cell in the bottom left corner.
  */
  int CountBottomLeftCorner();
  /*CountBottomRightCorner
  Returns an int representing the number of neighbors for the cell in the bottom right corner.
  */
  int CountBottomRightCorner();
  /*CountTopRow
  Parameters:
    y: an int representing the column of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell in the top row.
  */
  int CountTopRow(int y);
  /*CountBottomRow
  Parameters:
    y: an int representing the column of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell in the bottom row.
  */
  int CountBottomRow(int y);
  /*CountLeftColumn
  Parameters:
    x: an int representing the row of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell in the left column.
  */
  int CountLeftColumn(int x);
  /*CountRightColumn
  Parameters:
    x: an int representing the row of the current cell being evaluated
  Returns an int representing the number of neighbors for a given cell in the right column.
  */
  int CountRightColumn(int x);

};

#endif
