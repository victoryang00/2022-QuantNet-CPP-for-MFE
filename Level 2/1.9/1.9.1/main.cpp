#include <stdio.h>
#include <stdlib.h>
int main() {
  int c;
  printf("This program will print whatever content input before key ENTER is "
         "pressed.\nExit the program by pressing CTRL+D.\n");
  c = getchar();
  while (c != 4) {
    putchar(c);
    c = getchar();
  }
  if (c == 4) {
    printf("Ending.\n");
  }
}