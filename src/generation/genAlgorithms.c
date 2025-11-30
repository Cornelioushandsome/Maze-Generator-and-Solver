#include "./genAlgorithms.h"

void fillWalls(Maze *maze){
  for (int i = 0; i<maze->width * maze->height; i++){
    if (maze->cells[i] != START || maze->cells[i] != END){
      maze->cells[i] = WALL;
    }
  }

}

void shuffleDirections(int array[NUM_DIRECTIONS][NUM_DIFF]){
  for (int i = NUM_DIRECTIONS-1; i>0; i--){
    int r = (rand() % (i+1));
    int tmp_drow = array[r][D_ROW];
    int tmp_dcol = array[r][D_COL];
    array[r][D_ROW] = array[i][D_ROW];
    array[r][D_COL] = array[i][D_COL];
    array[i][D_ROW] = tmp_drow;
    array[i][D_COL] = tmp_dcol;
  }
}
