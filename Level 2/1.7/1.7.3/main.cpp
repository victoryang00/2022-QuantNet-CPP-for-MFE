/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a) printf("%d", (a)) // Print decimal
#define NL printf("\n");         // Print new line
// Create and initialse array
int a[] = {0, 1, 2, 3, 4};
int main() {
  int i;
  int *p;
  for (i = 0; i <= 4; i++)
    PRD(a[i]); // 1 : 01234
  NL;
  for (p = &a[0]; p <= &a[4]; p++)
    PRD(*p); // 2 : 01234
  NL;
  NL;
  for (p = &a[0], i = 0; i <= 4; i++)
    PRD(p[i]); // 3 : 01234
  NL;
  for (p = a, i = 0; p + i <= a + 4; p++, i++)
    PRD(*(p + i)); // 4 : 024
  NL;
  NL;
  for (p = a + 4; p >= a; p--)
    PRD(*p); // 5 : 43210
  NL;
  for (p = a + 4, i = 0; i <= 4; i++)
    PRD(p[-i]); // 6 : 43210
  NL;
  for (p = a + 4; p >= a; p--)
    PRD(a[p - a]); // 7 : 43210
  NL;
  return 0;
}