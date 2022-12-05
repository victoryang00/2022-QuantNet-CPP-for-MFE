#include <stdio.h>
void print() {
  extern float i;
  printf("2i = %.1f\n", 2 * i);
}