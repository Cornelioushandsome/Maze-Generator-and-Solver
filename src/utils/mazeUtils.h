#ifndef MAZE_UTILS_H
#define MAZE_UTILS_H

enum DIMENSION_BOUNDARIES{
  MAX_WIDTH  = 51,
  MAX_HEIGHT = 51,

  MIN_WIDTH  = 5,
  MIN_HEIGHT = 5
};

enum SYMBOLS {
  WALL  = '#',
  BLANK = '.',
  START = 'S',
  END   = 'E'
};

enum COMMAND_LIMITS{
  COMMAND_BUFSIZ = 32,
  DESCRIPTION_BUFSIZ = 256,
};

enum BOOL{
  FALSE = 0,
  TRUE = 1
};


typedef struct maze{
  char *cells; //contiguous array
  int width, height;
  char *start, *end;
} Maze;

typedef struct{
  char command[COMMAND_BUFSIZ];
  void (*helpMenu) (void);
  int  (*function) (char **);
}BuiltinCommand;

typedef struct{
  char command[COMMAND_BUFSIZ];
  char description[DESCRIPTION_BUFSIZ];
  void (*function) (Maze*);
}FunctionCommand;




void setStart(Maze *maze, int row, int col);
void setEnd(Maze *maze, int row, int col);

int isValidMaze(Maze *maze);
int isValidDimensions(int width, int height);
int isValidCell(Maze *maze, int row, int col);


static inline char *CELL(Maze *maze, int row, int col){

  // if (!isValidMaze){ // maybe unnecessary?
  //   return void;
  // }

  return (maze->cells + (row * maze->width) + col);
}

#endif