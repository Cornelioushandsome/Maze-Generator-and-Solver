#include <stdio.h>
#include "./utils/mazeUtils.h"
#include "./setup/mazeSetup.h"
#include "./generation/genAlgorithms.h"

int main(void){
  Maze *maze = initMaze(20, 20);
  plainGenerate(maze);  
  renderMaze(maze);
  freeMaze(maze);
  return 0;
}