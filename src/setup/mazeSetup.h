#ifndef MAZE_SETUP_H
#define MAZE_SETUP_H

#include "../utils/mazeUtils.h"


int isValidMaze(Maze *maze);
Maze *initMaze(int width, int height);
Maze *allocMaze(int width, int height);
void setStart(Maze *maze, int row, int col);
void setEnd(Maze *maze, int row, int col);
void renderMaze(Maze *maze);
void freeMaze(Maze *maze);

#endif