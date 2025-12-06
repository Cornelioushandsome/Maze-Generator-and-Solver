#include "./mazeUtils.h"

void setStart(Maze *maze, int row, int col){
  if (!maze || !isValidMaze(maze) || !isValidCell(maze, row, col)){
    return;
  }
  maze->start = CELL(maze, row, col);
  *maze->start = START; 


}
void setEnd(Maze *maze, int row, int col){
  if (!maze || !isValidMaze(maze) || !isValidCell(maze, row, col)){
    return;
  }
  maze->end = CELL(maze, row, col);
  *maze->end = END; 
}

int isValidDimensions(int width, int height){
  if (width < MIN_WIDTH || width > MAX_WIDTH\
      || height < MIN_HEIGHT || height > MAX_HEIGHT){
    return FALSE; 
  }
  return TRUE;
  //return (width >= MIN_WIDTH || width <= MAX_WIDTH ||height >= MIN_HEIGHT || height <= MAX_HEIGHT);
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

  //return (col >= 0 || col <maze->width || row >= 0 || row <maze->height);
}


