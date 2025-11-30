#include "./mazeShell.h"
#include "./mzshBuiltin.h"


#include "../setup/mazeSetup.h"
#include "../generation/genAlgorithms.h"
#include "../solver/solveAlgorithms.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Maze *GLOBAL_MAZE = NULL;

BuiltinCommand BuiltinCommandList[] = {
  {"init",    &helpInit,    &mzsh_init},
  {"gen",     &helpGen,     &mzsh_gen},
  {"solve",   &helpSolve,   &mzsh_solve},
  {"render",  &helpRender,  &mzsh_render},
  {"help",    &helpHelp,    &mzsh_help},
  {"quit",    &helpQuit,    &mzsh_quit},
};

FunctionCommand GenerationCommandList[] = {
  {"Plain"    , "Generate a plain maze with no inner-walls",  &plainGenerate},
  {"prim"     , "Create a maze using Prim's algorithm. \
Leads to short dead-ends",                                    &primGenerate},
  {"kruskal"  , "Create a maze using Kruskal's algorithm. \
Creates many short dead-ends",                                &kruskalGenerate},
  {"recursive", "Create a maze using recursive-backtracking. \
Leads to longer paths",                                       &recursiveBacktracking},
};

FunctionCommand SolveCommandList[] = {
  {"astar"    , "Finds the best path using cost and heuristics", &aStarSolver},
  {"dijkstra" , "Find the best path using cost and weights",     &dijkstraSolver},
  {"breadth"  , "Find the best path by exploring every \
direction equally.",                                             &breadthFirstSearch},
  {"recursive", "Find any path by using \
recursive-backtracking",                                         &depthFirstSearch}
};
static inline void promptHelp(void (*helpfunc)(void)){
  puts("Invalid input.");
  (helpfunc)();
  puts("Please try again.\n");
}


static inline int NumBuiltin(){ //not defined in header because of errors
  return sizeof(BuiltinCommandList)/sizeof(BuiltinCommandList[0]);
}

static inline int NumGenCommand(){
  return sizeof(GenerationCommandList)/sizeof(GenerationCommandList[0]);
}

static inline int NumSolveCommand(){
  return sizeof(SolveCommandList)/sizeof(SolveCommandList[0]);
}

BuiltinCommand *BuiltCommLookup(const char *command){
  int len = strlen(command);
  for (int i = 0; i<NumBuiltin(); i++){
    if (strcmp(command, BuiltinCommandList[i].command) == 0\
        ||(len == 1 && (*command) == *(BuiltinCommandList[i].command))){
      return BuiltinCommandList+i;
    }
  }
  return NULL;
}

FunctionCommand *FuncCommLookup(const char *command, FunctionCommand list[], const int n){
  int len = strlen(command);

  for (int i = 0; i<n; i++){
    if (strcmp(command, list[i].command) == 0\
        || (len == 1 && ((*command) == *(list[i].command)))){
      return list+i;
    }
  }
  return NULL;
}

int mzsh_launch(char **args){
  if ((*args)[0] == 'c') printf("\033[2J\033[1;1H");
  BuiltinCommand *command = BuiltCommLookup(args[0]);
  if (!command){
    puts("Invalid input. Please try again.");
    return 0; //just try again
  }
  return (*(command->function))(args);
  
}

int mzsh_init(char **args){ 
  
  if (!args[1] || !args[2] || helpValid(args)){
    helpInit();
    return 0;
  }
  int width  = (int) atoi(args[1]);
  int height = (int) atoi(args[2]);
  if (!isValidDimensions(width, height)){
    helpInit();
    return 0;
  }
  GLOBAL_MAZE = initMaze(width, height); //either success or terminated program
  puts("success");
  return EXIT_SUCCESS;
}

int mzsh_gen(char **args){
  if (helpValid(args)){
    helpGen();
    return 0;
  }
  if (!GLOBAL_MAZE || !isValidMaze(GLOBAL_MAZE)){
    puts("not initialized yet");
    return EXIT_FAILURE;
  }
  if (!args[1]){
    promptHelp(helpGen);
    return 0;
  }
  
  FunctionCommand *command = FuncCommLookup(args[1], GenerationCommandList, NumGenCommand());
  if (!command){
    promptHelp(helpGen);

    //just try again
    return 0;
  }
  (*(command->function))(GLOBAL_MAZE);
  return 0;

}

int mzsh_solve(char **args){
  if (helpValid(args)){
    helpSolve();
    return 0;
  }
  if (!GLOBAL_MAZE || !isValidMaze(GLOBAL_MAZE) || !GLOBAL_MAZE->start || !GLOBAL_MAZE->end){
    puts("not initialized or generated yet");
    return EXIT_FAILURE;
  }
  if (!args[1]){
    promptHelp(helpSolve);

    return 0; //prompt again
  }
  FunctionCommand *command = FuncCommLookup(args[1], SolveCommandList, NumSolveCommand());
  if (!command){
    promptHelp(helpSolve);
    return 0; //prompt again
  }
  (*(command->function))(GLOBAL_MAZE);
  
  return 0;
}

int mzsh_render(char **args){
  if (helpValid(args)){
    helpRender();
    return 0;
  }
  (void) args;
  if (!GLOBAL_MAZE){
    puts("Maze not initialized yet");
    return EXIT_FAILURE;
  }
  if (!isValidMaze(GLOBAL_MAZE) /*|| !GLOBAL_MAZE->start || !GLOBAL_MAZE->end*/){
    freeMaze(GLOBAL_MAZE);
    puts("Invalid maze");
    return EXIT_FAILURE;
  }
  renderMaze(GLOBAL_MAZE);
  puts("successfully rendered");
  return 0;
}

int helpValid(char **args){
  if (!args) return FALSE;
  for (char **i = args; *i; i++){
    if (**i == 'h') return TRUE;
  }
  return FALSE;
}



int mzsh_help(char **args){
  if (helpValid(args+1)){
    helpHelp();
    return 0;
  }
  (void) args;
  puts("Welcome to version 0.1 of MZSH: The maze generator and solver that provides a shell-interface");
  puts("Here is a list of all the available commands:\n");
  for (int i = 0; i<NumBuiltin(); i++){
    printf("%-7s%s%7s\n", "=====", BuiltinCommandList[i].command, "=====");
    (*(BuiltinCommandList[i].helpMenu))();
  }

  return EXIT_SUCCESS;
}

int mzsh_quit(char **args){
  if (helpValid(args)){
    helpQuit();
    return 0;
  }
  (void) args;
  
  if(GLOBAL_MAZE){
    freeMaze(GLOBAL_MAZE);
    GLOBAL_MAZE = NULL;
  }
  
  return EXIT_FAILURE;
}





void helpGen(void){
  printf("%s\n%s\n\n",
         "Generate a maze with walls and passages | Receives 1 argument(s) | Maze must already be initialized",
         "Usage:");
  printf("%25s\n%25s\n\n",
         ">gen <GEN-ALGORITHM>",
         ">g   <GEN-ALGORITHM>");
  puts("Here are the available commands for <gen>:\n");

  //print the algorithms
  for (int i = 0; i<NumGenCommand(); i++){
    printf("%10s%8s%6c\n", GenerationCommandList[i].command, "==>", *(GenerationCommandList[i].command));
    printf("%-5c}->   %s\n", ' ', GenerationCommandList[i].description);
  }
  
  putchar('\n');
}

void helpSolve(void){


  printf("%s\n%s\n\n",
         "Solve a maze | Receives 1 argument(s) | Maze must already be generated and initialized",
         "Usage:");
  printf("%29s\n%29s\n\n",
         ">solve <SOLVE-ALGORITHM>",
         ">s     <SOLVE-ALGORITHM>");
  puts("Here are the available commands for <solve>:\n");

  //print the algorithms
  for (int i = 0; i<NumGenCommand(); i++){
    printf("%10s%9s%6c\n", SolveCommandList[i].command, "==>", *(SolveCommandList[i].command));
    printf("%-5c}->   %s\n", ' ', SolveCommandList[i].description);

  }
  putchar('\n');
}

