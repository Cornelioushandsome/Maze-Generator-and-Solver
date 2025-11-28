#include "./mzshBuiltin.h"
#include <stdio.h>

void helpInit(void){
  puts("Initalize a maze with integer width and height dimensions | Receives 2 argument(s)");
  puts("\t\t\tUsage:");
  puts("\t\t\t\t>init <INT> <INT>");
  printf("\t\t\tValid dimensions:\n\
          \t\t\t%d<=WIDTH<=%d | %d<=HEIGHT<=%d\n",\
          MIN_WIDTH,MAX_WIDTH,MIN_HEIGHT,MAX_HEIGHT);

  putchar('\n');
}

void helpHelp(void){
  puts("Receive help with using the program");
  puts("\t\t\tUsage:");
  puts("\t\t\t\t>help");
  puts("\t\t\t\t>h");

  putchar('\n');
}
void helpQuit(void){
  puts("Quit the program and free the global maze");
  puts("\t\t\tUsage:");
  puts("\t\t\t\t>quit");
  puts("\t\t\t\t>q");

  putchar('\n');
}
void helpRender(void){
  puts("Print the global maze | Maze must be initialized and generated");
  puts("\t\t\tUsage:");
  puts("\t\t\t\t>render");
  puts("\t\t\t\t>r");

  putchar('\n');
}