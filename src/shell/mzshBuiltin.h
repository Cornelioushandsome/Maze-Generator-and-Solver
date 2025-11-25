#ifndef MZSH_BUILTIN_H
#define MZSH_BUILTIN_H

#define MZSH_COMMAND_BUFSIZ 32
#define MZSH_DESCRIPTION_BUFSIZ 256

#include "../utils/mazeUtils.h"

int mzsh_init(char **args);
int mzsh_gen(char **args);
int mzsh_solve(char **args);
int mzsh_help(char **args);
int mzsh_quit(char **args);

void handleGenPlain(Maze *maze);

typedef struct{
  char command[MZSH_COMMAND_BUFSIZ];
  char description[MZSH_DESCRIPTION_BUFSIZ];
  int (*function) (char **);
}BuiltinCommand;

typedef struct{
  char name[MZSH_COMMAND_BUFSIZ];
  void (*function) (Maze *);
}GenerateCommand;

typedef struct{
  char name[MZSH_COMMAND_BUFSIZ];
  void (*function) (Maze *);
}SolveCommand;


BuiltinCommand BuiltinCommandList[] = {
  {"init", "Initialize a maze in memory",&mzsh_init},
  {"gen", "Generate the walls of a maze that has already been initialized",&mzsh_gen},
  {"solve", "Solve a maze that has already been initialized and generated",&mzsh_solve},
  {"help", "Help with commands",&mzsh_help},
  {"quit", "Exit the program",&mzsh_quit}
};

static inline int NumBuiltin(){
  return sizeof(BuiltinCommandList)/sizeof(BuiltinCommandList[0]);
}

GenerateCommand GenerateCommandList[] = {
  {"plain", &handleGenPlain},
};


#endif