#include "./genAlgorithms.h"

void carveHelperFrom(Maze *maze, int row, int col){
  static int dirs[NUM_DIRECTIONS][NUM_DIFF] = DEFAULT_DIRECTIONS;
  shuffleDirections(dirs);

  int drow, dcol, nrow, ncol;

  for (int i = 0; i<NUM_DIRECTIONS; i++){
    drow = dirs[i][D_ROW];
    dcol = dirs[i][D_COL];

    nrow = row + drow*2;
    ncol = col + dcol*2;  

    if (isValidCell(maze, nrow, ncol) && *CELL(maze, nrow, ncol) == WALL){
      
      *CELL(maze, row, col)   = BLANK;
      *CELL(maze, row + (drow), col + (dcol)) = BLANK;
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