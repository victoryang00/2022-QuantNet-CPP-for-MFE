#include "Defs.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  float a, b, c;
  printf("Input a: ");
  scanf("%f", &a);
  printf("Input b: ");
  scanf("%f", &b);
  printf("Input c: ");
  scanf("%f", &c);
  printf("The maximum of a and b is: %.1f\n", MAX2(a, b));
  printf("The maximum of a,b and c is: %.1f\n", MAX3(a, b, c));
}