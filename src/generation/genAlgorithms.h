#ifndef GEN_ALGORITHMS_H
#define GEN_ALGORITHMS_H

#include "../utils/mazeUtils.h"
#include "../utils/algoUtils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SET_DEFAULT_START_END(maze)\
            setStart((maze), 1, 1);\
            setEnd((maze), ((maze)->height)-2, ((maze)->width)-2);\



extern int GLOBAL_DIRECTIONS[NUM_DIRECTIONS][NUM_DIFF];


void plainGenerate(Maze *maze);
void recursiveBacktracking(Maze *maze);
void primGenerate(Maze *maze);
void kruskalGenerate(Maze *maze);

void fillWalls(Maze *maze);
void shuffleDirections(int array[NUM_DIRECTIONS][NUM_DIFF]);
void carveHelperFrom(Maze *maze, int row, int col);


#endif