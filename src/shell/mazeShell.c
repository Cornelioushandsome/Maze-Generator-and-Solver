#include "./mazeShell.h"
#include "./mzshBuiltin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mzsh_readline(void){
  char *buffer = malloc(sizeof(char) * MZSH_MAX_LINE_SIZE);
  if (!buffer){
    fprintf(stderr, "mzsh_readline: failed to allocate memory to buffer\n");
    exit(EXIT_FAILURE);
  }
  int position = 0;
  int c;

  while((c = getchar()) != EOF && c != '\n'){
    buffer[position++] = c;


    if (position >= MZSH_MAX_LINE_SIZE){ 

      fprintf(stderr, "mzsh_readline: line exceeds character limit\n");
    }
  }

  //very ugly | maybe unnecessary
  if (c == EOF){
    putchar('\n');
    exit(EXIT_FAILURE);
  }

  buffer[position] = '\0';
  return buffer;
}

char **mzsh_splitline(char* line){
  int position = 0;
  char **tokens = malloc(MZSH_MAX_TOKENS * sizeof(char*));
  if (!tokens){
    fprintf(stderr, "mzsh_splitline: failed to allocate tokens\n");
    exit(EXIT_FAILURE);
  }
  char *curToken = strtok(line, MZSH_TOKEN_DELIM);
  while (curToken != NULL){
    tokens[position++] = curToken;
    if (position >= MZSH_MAX_TOKENS){
      fprintf(stderr, "mzsh_splitline: max tokens exceeded\n");
      exit(EXIT_FAILURE);
    }
    curToken = strtok(NULL, MZSH_TOKEN_DELIM);
  }
  tokens[position] = NULL;
  
  return tokens;
}
int mzsh_execute(char** args){
  if (args[0] == NULL) return 1;
  for (int i = 0; i < NumBuiltin(); i++){
    if (strcmp(args[0], BuiltinCommandList[i].command) == 0){
      return (*(BuiltinCommandList[i].function))(args);
    }
  }
  fprintf(stderr, "Invalid command. Please try again\n");
  return 0;
}

void mzsh_mainloop(void){
  char *line;
  char **args;
  int status;
  do{
    
    putchar('>');
    line = mzsh_readline();
    args = mzsh_splitline(line);

    status = mzsh_execute(args);

    free(line);
    free(args);

  }while(status == 0);
}

int mzsh_init(char **args){
  (void) args;
  puts("We are handling INIT");
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
  for (int i = 0; i < NumBuiltin(); i++){
    printf("\t%s\t-\t%s\n", BuiltinCommandList[i].command, BuiltinCommandList[i].description);
  }
  return 0;
}
int mzsh_quit(char **args){
  (void) args;
  puts("Exiting...");
  return 1;
}

void handleGenPlain(Maze *maze){
  (void) maze;
  puts("We are generating plain maze");

}
