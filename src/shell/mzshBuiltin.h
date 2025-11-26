#ifndef MZSH_BUILTIN_H
#define MZSH_BUILTIN_H

#define MZSH_COMMAND_BUFSIZ 32
#define MZSH_DESCRIPTION_BUFSIZ 256
#define MZSH_MAX_BUILTIN_COMMANDS 16

#include "../utils/mazeUtils.h"


int mzsh_init(char **args);
int mzsh_gen(char **args);
int mzsh_solve(char **args);
int mzsh_help(char **args);
int mzsh_quit(char **args);

//void handleGenPlain(Maze *maze);

typedef struct{
  char command[MZSH_COMMAND_BUFSIZ];
  char description[MZSH_DESCRIPTION_BUFSIZ];
  int (*function) (char **);
}BuiltinCommand;

extern BuiltinCommand BuiltinCommandList[];
int mzsh_launch(char **args);
inline int NumBuiltin();



#endif