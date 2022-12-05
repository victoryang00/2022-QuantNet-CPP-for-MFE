#include <stdio.h>
#include <stdlib.h>
int main() {
  float height, base;
  printf("Please enter the height.");
  scanf("%f", &height);
  printf("Please enter the base.");
  scanf("%f", &base);
  printf("The surface of the triangle is %f.\n", 0.5 * height * base);
}