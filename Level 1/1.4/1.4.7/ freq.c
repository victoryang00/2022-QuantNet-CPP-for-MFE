#include <stdio.h>
#include <stdlib.h>
int main() {
  int num, i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, j = 0;
  printf("Input integers from 0-4.\n");
  num = getchar();
  while (num != EOF) {
    switch (num) {
    case 48:
      i0++;
      break;
    case 49:
      i1++;
      break;
    case 50:
      i2++;
      break;
    case 51:
      i3++;
      break;
    case 52:
      i4++;
      break;
    default:
      j++;
      break;
    }
    num = getchar();
  }
  printf("Number 0 appears %d times.\n", i0);
  printf("Number 1 appears %d times.\n", i1);
  printf("Number 2 appears %d times.\n", i2);
  switch (i3) {
  case 0:
    printf("Number three appears zero time.\n");
    break;
  case 1:
    printf("Number three appears one time.\n");
    break;
  case 2:
    printf("Number three appears two times.\n");
    break;
  default:
    printf("Number three appears more than two times.\n");
    break;
  }
  printf("Number 4 appears %d times.\n", i4);
  printf("Other characters appear %d times.\n", j);
}