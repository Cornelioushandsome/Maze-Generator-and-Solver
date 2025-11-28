#include "./genAlgorithms.h"
#include <stdio.h>
void plainGenerate(Maze *maze){
  int i;
  for (i = 0; i < maze->width * maze->height; i++){
    if (i < maze->width || i > maze->width * (maze->height-1)-1\
     || i % maze->width == 0 || i % maze->width == maze->width-1){

      maze->cells[i] = WALL; 
    } else {
      maze->cells[i] = BLANK;
    }
  }
  setStart(maze, 1, 1);
  
  setEnd(maze, maze->height-2, maze->width-2);
  

  maze->cells[i] = '\0';
}