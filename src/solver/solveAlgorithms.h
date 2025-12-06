#ifndef SOLVE_ALGORITHMS_H
#define SOLVE_ALGORITHMS_H

#include "../utils/mazeUtils.h"
#include "../utils/algoUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void aStarSolver(Maze *maze);
void dijkstraSolver(Maze *maze);
void breadthFirstSearch(Maze *maze);
void depthFirstSearch(Maze *maze);

int searchFrom(Maze *maze, int row, int col);

#endif