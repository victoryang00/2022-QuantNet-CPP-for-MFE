/* Conditional expressions */
#include <stdio.h>
int main() {
  char ch;
  int i = 0, j = 0, k = 1;
  printf("Input Something with the ending of .l!?\n");
  ch = getchar();
  while (ch != '\x04') {
    if (ch != ' ' && ch != '\n') {
      i++;
    }
    if (ch == '\n') {
      k++;
    }
    if (ch == ' ' || ch == '!' || ch == ',' || ch == '.' || ch == ';' ||
        ch == '?') {
      j++;
      ch = getchar();
      while (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) {
        if (ch == '\x04') {
          break;
        }
        if (ch != ' ' && ch != '\n') {
          i++;
        }
        if (ch == '\n') {
          k++;
        }
        ch = getchar();
      }
      continue;
    }
    if (ch == '\x04') {
      break;
    }
    ch = getchar();
  }
  j > 0 ? j = j : j = 1;
  printf("the number of characters is %d\n", i);
  printf("the number of words is %d\n", j);
  printf("the number of lines is %d\n", k);
}