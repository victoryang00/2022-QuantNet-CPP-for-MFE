#include <stdio.h>
#include <stdlib.h>
int main() {
    int married;
    printf("Single enter 0 else anything else\n");
    scanf("%d", &married);
    married == 0 ? printf("You are married.") : printf("You are unmarried.");
}