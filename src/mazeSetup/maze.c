#include "mazeSetup/maze.h"

void allocMaze(Maze *maze, uint16_t width, uint16_t height){
    if (height > LIMIT_HEIGHT){
        fprintf(stderr, "Error: Height exceeds the LIMIT_HEIGHT of 255\n");
        exit(EXIT_FAILURE);
    }
    if (width > LIMIT_WIDTH){
        fprintf(stderr, "Error: Width exceeds the LIMIT_WIDTH of 255\n");
        exit(EXIT_FAILURE);
    }
    if (height % 2 == 0) {
        printf("Chaning height from (%d) to (%d) for better maze generation...\n", height, height + 1);
            height +=1;
        
    }
    if (width % 2 == 0){
        printf("Chaning width from (%d) to (%d) for better maze generation...\n", width, width + 1);
            width+=1;
        
    }

    maze->width = width;
    maze->height = height;
    maze->cells = malloc(maze->width*maze->height*sizeof(*maze->cells));
    if (!maze->cells){
        fprintf(stderr, "Error: Failed to malloc to maze->cells in allocMaze\n");
        exit(EXIT_FAILURE);
    }
}
void freeMaze(Maze *maze){
    if (maze && maze->cells ){
        free(maze->cells);
        maze->cells = NULL;
    }
}

void resizeMaze(Maze *maze, uint16_t n_width, uint16_t n_height){
    freeMaze(maze);
    allocMaze(maze, n_width, n_height);
}
void printMaze(Maze *maze){
    if (!maze){
        fprintf(stderr, "Error: Invalid maze address");
        return;
    }
    if (!(maze->width && maze->height)){
        fprintf(stderr, "Error: Invalid width or height when printing maze");
        return;
    }
    if (!maze->cells){
        fprintf(stderr, "Invalid maze->cells when printing maze");
        return;
    }

    uint16_t row, col;
    for (row = 0; row<maze->height; row++){
        for (col = 0; col <maze->width; col++){
            putchar(*cell(maze, row, col));
        }
        putchar('\n');
    }


}