#ifndef MZSH_BUILTIN_H
#define MZSH_BUILTIN_H



#include "../utils/mazeUtils.h"


int mzsh_init(char **args);
int mzsh_gen(char **args);
int mzsh_solve(char **args);
int mzsh_help(char **args);
int mzsh_quit(char **args);
int mzsh_render(char **args);

void helpInit(void);
void helpGen(void);
void helpSolve(void);
void helpHelp(void); //....fr?
void helpQuit(void);
void helpRender(void);

int helpValid(char **args);


void mzsh_genPlain(Maze *maze);



extern BuiltinCommand BuiltinCommandList[];
extern FunctionCommand GenerationCommandList[];

BuiltinCommand *BuiltCommLookup(const char* command);
FunctionCommand *FuncCommLookup(const char *command, FunctionCommand list[], const int n);

int mzsh_launch(char **args);






#endif