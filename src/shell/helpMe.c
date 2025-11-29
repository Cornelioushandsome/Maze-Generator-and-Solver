#include "./mzshBuiltin.h"
#include <stdio.h>

void helpInit(void){
  printf("%s\n%s\n\n%-5c%s\n%-5c%s\n\n%s\n\n",
         "Initalize a maze with integer width and height dimensions | Receives 2 argument(s)",
         "Usage:",
         ' ', ">init <INT> <INT>",
         ' ', ">i    <INT> <INT>",
         "Valid dimensions:");
  printf("%-5c%d<=WIDTH<=%d | %d<=HEIGHT<=%d\n",' ',MIN_WIDTH,MAX_WIDTH,MIN_HEIGHT,MAX_HEIGHT);
  putchar('\n');
}

void helpHelp(void){

  printf("%s\n%s\n\n%-5c%s\n%-5c%s\n",
         "Receive help with using the program",
         "Usage:",
         ' ', ">help",
         ' ', ">h");

  putchar('\n');
}
void helpQuit(void){
  printf("%s\n%s\n\n%-5c%s\n%-5c%s\n",
         "Quit the program and free the global maze",
         "Usage:",
         ' ', ">quit",
         ' ', ">q");

  putchar('\n');
}
void helpRender(void){

  printf("%s\n%s\n\n%-5c%s\n%-5c%s\n",
         "Print the global maze | Maze must be initialized and generated",
         "Usage:",
         ' ', ">render",
         ' ', ">r");

  putchar('\n');
}