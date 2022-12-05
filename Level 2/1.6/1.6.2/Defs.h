#define PRINT1(a) (printf("a=%.1f\n", a))
#define PRINT2(a, b)                                                           \
  (printf("a=%.1f\b=%.1f\n", a, b))
#define MAX2(a, b) (a > b ? a : b)
#define MAX3(a, b, c) (MAX2(MAX2(a, b), c))