#include "./solveAlgorithms.h"
#include "../setup/mazeSetup.h"


int searchFrom(Maze *maze, int row, int col){

  if(!isValidCell(maze, row, col)) return FALSE;

  char *cell = CELL(maze, row, col);
  if (*cell == WALL || *cell == VISITED) return FALSE;
  if (*cell == END) return TRUE;
  
  static int dirs[NUM_DIRECTIONS][NUM_DIFF] = DEFAULT_DIRECTIONS;

  *cell = VISITED;

  for (int i = 0; i<NUM_DIRECTIONS; i++){
    int n_row = row + dirs[i][D_ROW];
    int n_col = col + dirs[i][D_COL];

    if (searchFrom(maze, n_row, n_col)) return TRUE;

  }
  return FALSE;
  

}

void depthFirstSearch(Maze *maze){
  if (searchFrom(maze, 1, 1)) puts("Found");
  setStart(maze, 1,1);
}