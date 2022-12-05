#include <stdio.h>
#include <stdlib.h>
int main() {
  double Cel;
  double Fah = 0;
  printf("Compute the Fehrenheit and Celsius Transformation\n");
  for (Cel = 0.; Cel <= 19; Cel++) {
    Fah=9*Cel/5+32;
    printf("%10.1f,%10.1f\n", Fah, Cel);
  }
}
