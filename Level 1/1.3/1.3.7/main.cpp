#include <stdio.h>
#include <stdlib.h>
int main() {
  int a, n, b;
  printf("To compute a*(2^n)\n Input a: ");
  scanf("%d", &a);
  printf("Input n: ");
  scanf("%d", &n);
  b = a << n;
  printf("Result: %d\n", b);
}