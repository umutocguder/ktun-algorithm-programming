#include "stdio.h"
#include "string.h"
struct student{
  char name[15];
  char surname[15];
  int number;
  int age;
}ahmet,mehmet;
int main() {
  char a[15];
  //ahmet={0,6,8,6};
  gets(a);
  strcopy(ahmet.name,"a");
  scanf("%d",&ahmet.number);
  scanf("%d",&ahmet.age);
  printf("%s %d %s %d",ahmet.name,ahmet.number,ahmet.surname,ahmet.age );
  return 0;
}
