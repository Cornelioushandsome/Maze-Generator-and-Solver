#ifndef MAZE_SHELL_H
#define MAZE_SHELL_H

#define MZSH_MAX_LINE_SIZE 1024
#define MZSH_MAX_TOKENS 64
#define MZSH_TOKEN_DELIM " \t\n\r\a"

char *mzsh_readline(void);
char **mzsh_splitline(char* line);
int mzsh_execute(char** args);
void mzsh_mainloop(void);

#endif