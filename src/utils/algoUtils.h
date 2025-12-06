#ifndef ALGO_UTILS_H
#define ALGO_UTILS_H




//      d_row, d_col   |N, E, S, W
#define DEFAULT_DIRECTIONS \
{{-1,0}, {0, 1}, {1, 0}, {0, -1}}

#define NUM_DIRECTIONS 4
#define NUM_DIFF 2


enum DIRECTIONS{
  N = 0,
  E,
  S,
  W
};

enum DIFFERENCES{
  D_ROW = 0,
  D_COL
};


#endif 
