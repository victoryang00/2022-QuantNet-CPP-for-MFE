#include <stdio.h>
#include <stdlib.h>
void Swap(float *pfa, float *pfb);
int main() {
  float a, b;
  printf("Input a: ");
  scanf("%f", &a);
  printf("Input b: ");
  scanf("%f", &b);
  printf("first swap a=%.1f, b=%.1f.\n", a, b);
  Swap(&a, &b);
  printf("second swap, a=%.1f, b=%.1f.\n", a, b);
}
void Swap(float *pfa, float *pfb) {
  float mid = (*pfa); 
  (*pfa) = (*pfb);
  (*pfb) = mid;
}