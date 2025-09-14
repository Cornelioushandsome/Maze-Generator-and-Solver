#include "genAlgorithms/genAlgorithms.h"


void _carveHelper(Maze *maze, uint16_t row, uint16_t col){
    int dirs[4][2] = {{-2,0},{2,0},{0,-2},{0,2}};
    //shuffle dirs
    uint16_t i;
    for (i = 0; i<4; i++){
        int randomNum = i + rand() % (4 - i);
        int tempDRow = dirs[i][0], tempDCol = dirs[i][1];
        dirs[i][0] = dirs[randomNum][0]; dirs[i][1] = dirs[randomNum][1];
        dirs[randomNum][0] = tempDRow; dirs[randomNum][1] = tempDCol;

    }
    for (i = 0; i< 4; i++){
        int curRow = row + dirs[i][0], curCol = col+dirs[i][1];
        if (curRow > 0 && curCol > 0 && curRow < maze->height -1  && curCol < maze->width - 1 && *cell(maze, curRow, curCol) == WALL){
            *cell(maze, curRow, curCol) = BLANK;
            *cell(maze, row + dirs[i][0]/2, col+dirs[i][1]/2) = BLANK;
            _carveHelper(maze, curRow, curCol);
        }
    }

}

int generateMazeRecursiveBacktracking(Maze *maze){ 
    if (!maze || !maze->cells) return -1;
    //fill everything with walls

    uint16_t row, col;
    for (row = 0; row<maze->height; row++){
        for (col = 0; col<maze->width; col++){
            *cell(maze, row, col) = WALL;
        }
    }

    *cell(maze, START_ROW, START_COL) = BLANK;
    _carveHelper(maze, START_ROW, START_COL);

    *cell(maze, START_ROW, START_COL) = START;
    *cell(maze, maze->height-2, maze->width-2) = END;
    return 0;
}
