#include "mazeSetup/maze.h"
#include "genAlgorithms/genAlgorithms.h"

int main(){
    srand(time(NULL));
    
    Maze maze;
    uint16_t width = 50, height = 50;
    allocMaze(&maze, width, height);

    generateMazeRecursiveBacktracking(&maze);
    printMaze(&maze);

    freeMaze(&maze);

    return EXIT_SUCCESS;
}
