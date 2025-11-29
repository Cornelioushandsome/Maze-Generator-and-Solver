#include "./mazeSetup.h"
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


void renderMaze(Maze *maze){
  if (!isValidMaze(maze)){
    fprintf(stderr, "renderMaze: Invalid maze\n");
    exit(EXIT_FAILURE);
  }
  int i;
  for (i = 0; i < maze->width * maze->height; i++){
    if (i % maze->width == 0) putchar('\n');
    putchar(maze->cells[i]);
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