#include <stdio.h>
#include <stdlib.h>
int main() {
    int c;
    char f[128];
    printf("This program will print whatever content input before key ENTER is "
           "pressed\nto a file assigned by the user.\nExit the program by "
           "pressing CTRL+D.\n");
    scanf("%d", f);

    FILE *fp;
    fp = fopen(f, "w");
    while ((c = getchar()) != 4) {
        fputc(c, fp);
    }
    if (c == 4) {
        printf("CTRL + D is a correct ending.\n");
    }
    printf("Check the file under project folder.\n");
    fclose(fp);
}