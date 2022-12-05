#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Article {
  int ArtNum;
  int Quant;
  char Descrip[20];
};
void Print(struct Article *pt);
int main() {
  struct Article Art1;

  Art1.ArtNum = 1;
  Art1.Quant = 4;
  strcpy(Art1.Descrip, "something about C");

  Print(&Art1);
}
void Print(struct Article *pt) {
  printf("Article Number of Art1 is: %d\n", pt->ArtNum);
  printf("Quantity of Art1 is: %d\n", pt->Quant);
  printf("Description of Art1 is: %s\n", pt->Descrip);
}