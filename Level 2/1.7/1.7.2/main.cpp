#include <stdio.h>
#define MAXLINE 30
int Length(char str[]);
int main() {
  char string[MAXLINE + 1];
  int c;
  int i = 0;

  printf("Type up to %d chars. Exit with ^Z.\n", MAXLINE);

  while ((c = getchar()) != EOF && i < MAXLINE) {
    string[i++] = (char)c;
  }
  string[i] = '\0';
  printf("String length is %d characters.\n", Length(string));
  return 0;
}
int Length(char str[]) {
  int length;
  for (length = 0; str[length] != '\0'; length++);
  length--;
  return length;
}