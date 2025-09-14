#ifndef GEN_ALGORITHMS_H
#define GEN_ALGORITHMS_H
#include "mazeSetup/maze.h"

enum START{
    START_ROW = 1,
    START_COL = 1
};

typedef struct{
    uint16_t row;
    uint16_t col;

    uint16_t parentRow;
    uint16_t parentCol;
    
} Wall;

static inline void addWall(Maze *maze, Wall *wallList, uint32_t *wallCount, uint16_t row, uint16_t col, uint16_t parentRow, uint16_t parentCol){
    if (row >= maze->height || col >= maze->width) return;
    
    wallList[*wallCount].row = row;
    wallList[*wallCount].col = col;
    wallList[*wallCount].parentRow = parentRow;
    wallList[*wallCount].parentCol = parentCol;
    (*wallCount)++;
    
}


int generateMazePrim(Maze *maze);
int generateMazeRecursiveBacktracking(Maze *maze); //will change even dimensions to odd dimensions
void _carveHelper(Maze *maze, uint16_t row, uint16_t col);

#endif