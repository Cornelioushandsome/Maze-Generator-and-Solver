#include "./mazeUtils.h"

void setStart(Maze *maze, int row, int col){
  if (!isValidMaze(maze)){
    return;
  }
  *CELL(maze, row, col) = START;

}
void setEnd(Maze *maze, int row, int col){
  if (!isValidMaze(maze)){
    return;
  }
  *CELL(maze, row, col) = END;
}

int isValidMaze(Maze *maze){
  if (!maze && !maze->cells){
    return 0;
  }
  if (maze->width < MIN_WIDTH || maze->width > MAX_WIDTH\
  || maze->height < MIN_HEIGHT || maze->width > MAX_HEIGHT){
    return 0;
  }
  return 1;
}

int isValidCell(Maze *maze, int row, int col){
  if (col < 0 || col >= maze->width || row < 0 || row >= maze->height){
    return 0;
  }
  return 1;
}