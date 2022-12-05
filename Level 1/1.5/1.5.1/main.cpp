#include <stdio.h>
#include <stdlib.h>
float minus(float a, float b) {
  float c;
  c = a - b;
  return c;
}
int main() {
  float a, b, c;
  printf("Input a: ");
  scanf("%f", &a);
  printf("Input b: ");
  scanf("%f", &b);
  c = minus(a, b);
  printf("The difference between %.1f and %.1f is: %.1f\n", a, b, c);
}
