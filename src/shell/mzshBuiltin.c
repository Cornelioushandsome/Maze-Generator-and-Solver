#include "./mazeShell.h"
#include "./mzshBuiltin.h"


#include "../setup/mazeSetup.h"
#include "../generation/genAlgorithms.h"

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
  {"plain", "Generate a plain maze", &mzsh_genPlain},
};

FunctionCommand SolveCommandList[] = {

};


inline int NumBuiltin(){ //not defined in header because of errors
  return sizeof(BuiltinCommandList)/sizeof(BuiltinCommandList[0]);
}

inline int NumGenCommand(){
  return sizeof(GenerationCommandList)/sizeof(GenerationCommandList[0]);
}

inline int NumSolveCommand(){
  return sizeof(SolveCommandList)/sizeof(SolveCommandList[0]);
}

BuiltinCommand *BuiltCommLookup(const char *command){
  for (int i = 0; i<NumBuiltin(); i++){
    if (strcmp(command, BuiltinCommandList[i].command) == 0\
        ||(strlen(command) == 1 && (*command) == *(BuiltinCommandList[i].command))){
      return BuiltinCommandList+i;
    }
  }
  return NULL;
}
FunctionCommand *FuncCommLookup(const char *command, FunctionCommand list[], const int n){
  //if (!command) return NULL;
  for (int i = 0; i<n; i++){
    if (strcmp(command, list[i].command) == 0\
        || (strlen(command) == 1 && ((*command) == *(list[i].command)))){
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
    puts("Invalid input for <GEN>. Please try again");
    return 0;
  }
  
  FunctionCommand *command = FuncCommLookup(args[1], GenerationCommandList, NumGenCommand());
  if (!command){
    puts("Invalid input for <GEN>. Please try again");
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
  (void) args;

  puts("We are handling SOLVE");
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
  if (!isValidMaze(GLOBAL_MAZE)){
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
    printf("\t%s\t-\t", BuiltinCommandList[i].command);
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


void mzsh_genPlain(Maze *maze){
  //maybe unnecessary?
  if (!maze){
    puts("Maze not initialized yet");
    exit(EXIT_FAILURE);
  }
  if (!isValidMaze(maze)){
    freeMaze(maze);
    puts("Invalid maze");
    exit(EXIT_FAILURE);
  }
  plainGenerate(maze);
  puts("successful generating plain maze");
}


void helpGen(void){
  puts("Generate a maze with walls and passages | Receives 1 argument(s) | Maze must already be initialized\n\
        \t\t\tUsage:\n\
        \t\t\t\t>gen <GEN-ALGORITHM>\n\
        \t\t\t\t>gen <GEN-ALGORITHM>\n\
        \t\t\tHere are the available commands for <gen>:");

  //print the algorithms
  for (int i = 0; i<NumGenCommand(); i++){
    printf("\t\t\t\t%s\n", GenerationCommandList[i].command);
  }
  
  putchar('\n');
}

void helpSolve(void){
  puts("Solve a maze | Receives 1 argument(s) | Maze must already be generated and initialized");
  puts("\t\t\tUsage:");
  puts("\t\t\t\t>solve <SOLVE-ALGORITHM>");
  puts("\t\t\t\t>s     <SOLVE-ALGORITHM>");
  puts("\t\t\tHere are the available commands for <solve>:");
  //print the algorithms
  for (int i = 0; i<NumSolveCommand(); i++){
    printf("\t\t\t\t%s\n", SolveCommandList[i].command);
  }
  putchar('\n');
}

