#include "./mazeSetup.h"
#include "../utils/algoUtils.h"
#include <stdlib.h>
#include <stdio.h>


Maze *allocMaze(int width, int height){

  Maze *maze = malloc(sizeof(Maze));
  if (!maze) exit(EXIT_FAILURE);

  maze->cells = malloc(sizeof(char) * width * height);
  if (!maze->cells){
    free(maze);
    exit(EXIT_FAILURE);
  }

  return maze;

}

Maze *initMaze(int width, int height){
  if (!isValidDimensions(width, height)) return NULL;
  if (width % 2 == 0){
    width++;
    printf("Changed width to %d for better maze generation...\n", width);
  }
  if (height % 2 == 0){
    height++;
    printf("Changed height to %d for better maze generation...\n", height);
  }

  Maze *newMaze = allocMaze(width, height);
  if (!newMaze){
    fprintf(stderr, "initMaze()->allocMaze(): failed to allocate maze\n");
    exit(EXIT_FAILURE);
  }
  newMaze->width = width;
  newMaze->height = height;
  newMaze->start = NULL;
  newMaze->end = NULL;

  return newMaze;

}



void handleSymCases(Maze *maze, int row, int col, const char SYM_TYPE, const char* COLOR_ESCAPE_CODE){
  //this is ugly
  static int dirs[NUM_DIRECTIONS][NUM_DIFF] = DEFAULT_DIRECTIONS;
  char neighbors[NUM_DIRECTIONS];
  int wall_count = 0;

  for (int i = 0; i<NUM_DIRECTIONS; i++){
    int n_row = row + dirs[i][D_ROW];
    int n_col = col + dirs[i][D_COL];
    
    if (!isValidCell(maze, n_row, n_col) || *CELL(maze, n_row, n_col) != SYM_TYPE){
      neighbors[i] = BLANK;
      continue;
    }
    neighbors[i] = SYM_TYPE;
    wall_count++;
  }
  fputs(COLOR_ESCAPE_CODE, stdout);
  switch(wall_count){
    case 4:
      fputs("\u253C", stdout);
      break;
    case 3:
      if (neighbors[N] == BLANK)            fputs("\u252C", stdout);  //orig: printf("\u252C");
      else if (neighbors[E] == BLANK)       fputs("\u2524", stdout);
      else if (neighbors[S] == BLANK)       fputs("\u2534", stdout); //orig: printf("\u2534");
      else if (neighbors[W] == BLANK)       fputs("\u251C", stdout);
      break;
    case 2:
      if (neighbors[N] == SYM_TYPE){
        if (neighbors[E] == SYM_TYPE)       fputs("\u2514", stdout);
        else if (neighbors[S] == SYM_TYPE)  fputs("\u2502", stdout);
        else if (neighbors[W] == SYM_TYPE)  fputs("\u2518", stdout);
      }
      else if (neighbors[S] == SYM_TYPE){
        if (neighbors[E] == SYM_TYPE)       fputs("\u250C", stdout);
        else if (neighbors[W] == SYM_TYPE)  fputs("\u2510", stdout);
      }
      else if (neighbors[E] == SYM_TYPE\
        && neighbors[W] == SYM_TYPE)        fputs("\u2500", stdout);
      break;
    case 1:
      if (neighbors[N] == SYM_TYPE)         fputs("\u2575", stdout);
      else if (neighbors[E] == SYM_TYPE)    fputs("\u2576", stdout);
      else if (neighbors[S] == SYM_TYPE)    fputs("\u2577", stdout);
      else if (neighbors[W] == SYM_TYPE)    fputs("\u2574", stdout);
      break;
    default:
      // fprintf(stderr, "renderMaze: There was an error with rendering the maze\n");
      // exit(EXIT_FAILURE);
      break;
  }
  fputs("\x1b[0m", stdout);

}


void renderMaze(Maze *maze){
  if (!isValidMaze(maze)){
    fprintf(stderr, "renderMaze: Invalid maze\n");
    exit(EXIT_FAILURE);
  }
  for (int row = 0; row < maze->height; row++){
    for (int col = 0; col < maze->width; col++){
      
      switch(*CELL(maze, row, col)){
        case WALL:
          
          handleSymCases(maze, row, col, WALL, "\x1b[1;37m");
          
          break;
        case VISITED:
          handleSymCases(maze, row, col, VISITED, "\x1b[32m");
          
          break;
        default:
          putchar(*CELL(maze, row, col));
          break;
      }
    }
    putchar('\n');
  }


  putchar('\n');

}


void freeMaze(Maze *maze){
  if (maze){
    if (maze->cells){
      free(maze->cells);
      maze->cells = NULL;
    }
    free(maze);
    maze = NULL;
  }
  puts("called freeMaze");
  
}