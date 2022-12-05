#include <stdio.h>
#include <stdlib.h>
int main() {
  int a, b, c;
  printf("Enter integer: ");
  scanf("%d", &a);
  b = a >> 1;
  c = b >> 1;
  printf("a>>1=%d,\na>>2=%d.\n", b, c);
  if (b < 0) {
    printf("A 1 is the second input be inserted\n");
  } else {
    printf("A 0 is the second input be inserted\n");
  }
  if (c < 0) {
    printf("A 1 is the first input be inserted\n");
  } else {
    printf("A 0 is the first input be inserted\n");
  }
}
