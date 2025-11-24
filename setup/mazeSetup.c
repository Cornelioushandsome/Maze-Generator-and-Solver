#include "./mazeSetup.h"
#include <stdlib.h>
#include <stdio.h>


Maze *allocMaze(int width, int height){
  Maze *maze = malloc(sizeof(Maze));
  if (!maze){
    return NULL;
  }
  maze->cells = malloc(sizeof(char) * width * height);
  if (!maze->cells){
    return NULL;
  }

  return maze;

}

Maze *initMaze(int width, int height){
  if (width < MIN_WIDTH || width > MAX_WIDTH || height < MIN_HEIGHT || height > MAX_HEIGHT){
    return NULL;
  }
  if (width % 2 == 0){
    width++;
    printf("Changed width to %d for better maze generation...\n", width);
  }
  if (height % 2 == 0){
    height++;
    printf("Changed height to %d for better maze generation...\n", height);
  }

  Maze *newMaze = allocMaze(width, height);
  newMaze->width = width;
  newMaze->height = height;

  return newMaze;

}


void renderMaze(Maze *maze){
  if (!maze){
    fprintf(stderr, "renderMaze: maze not allocated\n");
    exit(EXIT_FAILURE);
  }
  if (!maze->cells){
    fprintf(stderr, "renderMaze: maze->cells not allocated\n");
    exit(EXIT_FAILURE);
  }

  int i;
  for (i = 0; i<maze->width * maze->height; i++){
    if (i % maze->width == 0) putchar('\n');
    putchar(maze->cells[i]);
  }

  putchar('\n');

}

void freeMaze(Maze *maze){
  if (maze){
    if (maze->cells){
      free(maze->cells);
    }
    free(maze);
  }
}