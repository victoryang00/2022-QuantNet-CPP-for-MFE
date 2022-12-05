#include <stdio.h>
#include <stdlib.h>
int main() {
  int first_i = 10, second_i = 10, first_res = 1, second_res = 1;
  printf("To Show the differnce between --i and i--\n");
  first_res = --first_i;
  printf("Do r=--i, we get r=%d, i=%d\n", first_res, first_i);
  second_res = second_i--;
  printf("Do r=i--, we get r=%d, i=%d\n", second_res, second_i);
}
