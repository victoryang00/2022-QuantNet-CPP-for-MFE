#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void DayName(int day);
int main() {
  int day;
  printf("This program will print the day of a given day number.\n");
  printf("Input a day number: ");
  scanf("%d", &day);
  DayName(day);
  printf("\n");
}
void DayName(int day) {
  int i = 0;
  char Day[7][10] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                     "Friday", "Saturday", "Sunday"};
  printf("Day %d is ", day);
  for (i = 0; i < 10; i++) {
    printf("%c", Day[day - 1][i]);
  }
}