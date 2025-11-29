#ifndef SOLVE_ALGORITHMS_H
#define SOLVE_ALGORITHMS_H

#include "../utils/mazeUtils.h"
#include <stdio.h>

void aStarSolver(Maze *maze);
void dijkstraSolver(Maze *maze);
void breadthFirstSearch(Maze *maze);
void depthFirstSearch(Maze *maze);

#endif