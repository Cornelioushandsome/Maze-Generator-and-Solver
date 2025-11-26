#include "./mazeShell.h"
#include "./mzshBuiltin.h"


#include "../setup/mazeSetup.h"
//#include "../generation/genAlgorithms.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Maze *GLOBAL_MAZE;

BuiltinCommand BuiltinCommandList[] = {
  {"init", "Initialize a maze in memory",&mzsh_init},
  {"gen", "Generate the walls of a maze that has already been initialized",&mzsh_gen},
  {"solve", "Solve a maze that has already been initialized and generated",&mzsh_solve},
  {"help", "Help with commands",&mzsh_help},
  {"quit", "Exit the program", &mzsh_quit},
  
};

inline int NumBuiltin(){
  return sizeof(BuiltinCommandList)/sizeof(BuiltinCommandList[0]);
}

int mzsh_launch(char **args){
  if ((*args)[0] == 'c') printf("\033[2J\033[1;1H");
  for (int i = 0; i<NumBuiltin(); i++){
    //match word or first letter
    if (strcmp(args[0], BuiltinCommandList[i].command) == 0\
        || (*args)[0] == BuiltinCommandList[i].command[0]){ 
      return (*(BuiltinCommandList[i].function))(args);
    }
  } 

  puts("Invalid input. Please try again.");
  return 0;
}

int mzsh_init(char **args){
  (void) args;
  puts("we are handling INIT");
  return 0;
}
int mzsh_gen(char **args){
  (void) args;

  puts("We are handling GEN");
  return 0;
}
int mzsh_solve(char **args){
  (void) args;

  puts("We are handling SOLVE");
  return 0;
}
int mzsh_help(char **args){
  (void) args;
  puts("Welcome to version 0.1 of MZSH: The maze generator and solver that provides a shell-interface\n");
  puts("Here is a list of all the available commands:\n");
  //printf("\t%s\t-\t%s\n", i->command, i->description);
  for (int i = 0; i<NumBuiltin(); i++){
    printf("\t%s\t-\t%s\n", BuiltinCommandList[i].command, BuiltinCommandList[i].description);
  }

  return EXIT_SUCCESS;
}
int mzsh_quit(char **args){
  (void) args;
  freeMaze(GLOBAL_MAZE);
  putchar('\n');
  return EXIT_FAILURE;
}