#include "Defs.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  float a, b;
  printf("Input a: \n");
  scanf("%f", &a);
  printf("Input b: \n");
  scanf("%f", &b);
  PRINT1(a);
  PRINT2(a, b);
}