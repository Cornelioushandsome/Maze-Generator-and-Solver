#include "./mazeShell.h"
#include "./mzshBuiltin.h"


#include "../setup/mazeSetup.h"
//#include "../generation/genAlgorithms.h"

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
      free(buffer);
      exit(EXIT_FAILURE);
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
    free(line);
    exit(EXIT_FAILURE);
  }
  char *curToken = strtok(line, MZSH_TOKEN_DELIM);
  while (curToken != NULL){
    tokens[position++] = curToken;
    if (position >= MZSH_MAX_TOKENS){
      fprintf(stderr, "mzsh_splitline: max tokens exceeded\n");
      free(curToken);
      free(line);
      free(tokens);
      exit(EXIT_FAILURE);
    }
    curToken = strtok(NULL, MZSH_TOKEN_DELIM);
  }
  tokens[position] = NULL;
  
  return tokens;
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

  }while(status == EXIT_SUCCESS);

  mzsh_quit((char**) NULL);
}

int mzsh_execute(char** args){

  if (!args && args[0] == NULL) return EXIT_FAILURE;
  return mzsh_launch(args);
}






