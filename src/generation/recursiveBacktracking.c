#include "./genAlgorithms.h"

void carveHelperFrom(Maze *maze, int row, int col){
  static int dirs[4][2] = DEFAULT_DIRECTIONS;
  shuffleDirections(dirs);

  int drow, dcol, nrow, ncol;

  for (int i = 0; i<NUM_DIRECTIONS; i++){
    drow = dirs[i][D_ROW];
    dcol = dirs[i][D_COL];

    nrow = row + drow;
    ncol = col + dcol;  

    if (isValidCell(maze, nrow, ncol) && *CELL(maze, nrow, ncol) == WALL){
      
      *CELL(maze, row, col)   = BLANK;
      *CELL(maze, row + (drow/2), col + (dcol/2)) = BLANK;
      *CELL(maze, nrow, ncol) = BLANK;

      carveHelperFrom(maze, nrow, ncol);
      
    }
  }
}

void recursiveBacktracking(Maze *maze){
  fillWalls(maze);
  srand(time(NULL));
  
  carveHelperFrom(maze, 1, 1);
  SET_DEFAULT_START_END(maze);
  puts("success with recursive backtracking");
}