#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#include <time.h> //for rand()



enum LIMITS{
    LIMIT_WIDTH = 255,
    LIMIT_HEIGHT = 255
};

enum SYMBOLS{
    START = 'S',
    END = 'E',
    WALL = '#',
    BLANK = ' '
};

typedef struct{
    uint16_t height;
    uint16_t width;
    char *cells;
} Maze;

static inline char* cell(Maze *maze, uint16_t row, uint16_t col){
    if (row >= maze->height || col >= maze->width){
        fprintf(stderr, "CELL error: (%u, %u) out of bounds\n", row, col);
        return NULL;
    }
    return &(maze->cells[row * maze->width+col]);
}



void allocMaze(Maze *maze, uint16_t width, uint16_t height); //exit program if error
void freeMaze(Maze *maze);
void resizeMaze(Maze *maze, uint16_t n_width, uint16_t n_height); //calls freeMaze() and allocMaze()
void printMaze(Maze *maze);


#endif