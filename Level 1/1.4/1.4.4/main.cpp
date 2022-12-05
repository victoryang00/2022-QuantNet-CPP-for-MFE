#include <stdio.h>
#include <stdlib.h>
int main() {
  double Cel;
  double Fah = 0;
  printf("Compute the Fehrenheit and Celsius Transformation\n");
  while (Fah < 301) {
    Cel = (Fah - 32) * 5 / 9;
    printf("%10.1f,%10.1f\n", Fah, Cel);
    Fah += 20;
  }
}
