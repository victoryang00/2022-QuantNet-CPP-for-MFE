#include <stdio.h>
#include <stdlib.h>
int main() {
  char ch;
  int i = 0, j = 0, k = 1;
  printf("Input some contents ends with a space.\n");
  ch = getchar();
  while (ch != '\x04') {
    switch (ch) {
    case '\n':
      k++;
      break;
    case ' ':
      j++;
      break;
    default:
      i++;
      break;
    }
    ch = getchar();
  }
  j > 0 ? j = j : j = 1; 
  printf("The number of characters is: %d\n", i);
  printf("The number of words is: %d\n", j);
  printf("The number of lines is: %d\n", k);
}