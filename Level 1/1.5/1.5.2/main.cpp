#include <stdio.h>
#include <stdlib.h>
int factorial(int n) {
  int fac;
  switch (n) {
  case 0:
    fac = 1;
    break;
  case 1:
    fac = 1;
    break;
  default:
    fac = n * factorial(n - 1);
    break;
  }
  return fac;
}
int main() {
  int n, fac;
  printf("Input integer: ");
  scanf("%d", &n);
  fac = factorial(n);
  printf("The factorial of %d is: %d\n", n, fac);
}