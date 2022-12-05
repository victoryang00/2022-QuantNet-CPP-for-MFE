#include <stdio.h>
#include <stdlib.h>
long double printnumber(long double a) {
  if (a < 0) {
    a = -a;
    putchar(45);
  }
  long double num;
  int d;
  if (a > 10) {
    num = printnumber(a / 10);
    d = (int)num;
    d = d % 10;
    d += 48;
    putchar(d);
    return (10 * num);
  } else {
    d = a;
    d = d % 10;
    d += 48;
    putchar(d);
    return (10 * a);
  }
}
int main() {
  float a;
  printf("Input an integer with <= 8 digits: ");
  scanf("%f", &a);
  printnumber(a);
}