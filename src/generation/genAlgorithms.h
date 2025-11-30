#ifndef GEN_ALGORITHMS_H
#define GEN_ALGORITHMS_H

#define SET_DEFAULT_START_END(maze)\
            setStart((maze), 1, 1);\
            setEnd((maze), ((maze)->height)-2, ((maze)->width)-2);\

#include "../utils/mazeUtils.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_DIRECTIONS 4
#define NUM_DIFF 2

//      d_row, d_col   |N, E, S, W
#define DEFAULT_DIRECTIONS \
          {{2,0}, {0, 2}, {-2, 0}, {0, -2}}

enum DIRECTIONS{
  N = 0,
  E,
  S,
  W
};

enum DIFFERENCES{
  D_ROW = 0,
  D_COL
};

extern int GLOBAL_DIRECTIONS[NUM_DIRECTIONS][NUM_DIFF];


void plainGenerate(Maze *maze);
void recursiveBacktracking(Maze *maze);
void primGenerate(Maze *maze);
void kruskalGenerate(Maze *maze);

void fillWalls(Maze *maze);
void shuffleDirections(int array[NUM_DIRECTIONS][NUM_DIFF]);
void carveHelperFrom(Maze *maze, int row, int col);


#endif