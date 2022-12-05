#include <stdio.h>
#include <stdlib.h>
float i;
void print();
int main() {
  printf("Please assign a value to i: ");
  scanf("%f", &i);
  print();
}