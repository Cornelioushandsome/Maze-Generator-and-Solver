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

int isValidDimensions(int width, int height){
  if (width < MIN_WIDTH || width > MAX_WIDTH\
      || height < MIN_HEIGHT || height > MAX_HEIGHT){
    return FALSE; 
  }
  return TRUE;
}

int isValidMaze(Maze *maze){
  if (!maze || !maze->cells){
    return FALSE;
  }
  return isValidDimensions(maze->width, maze->height);
}

int isValidCell(Maze *maze, int row, int col){
  if (col < 0 || col >= maze->width || row < 0 || row >= maze->height){
    return FALSE;
  }
  return TRUE;
}


