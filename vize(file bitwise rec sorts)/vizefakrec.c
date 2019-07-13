#include "stdio.h"
int fak(int sayi,int ussu){
if (ussu<=1) {
  return sayi;
}
else
{
  return sayi*fak(sayi,ussu-1);
}
}
int main(int argc, char const *argv[]) {
int a,b;

  printf("bir sayi giriniz ");
  scanf("%d",&a );
  printf("ussunu giriniz");
  scanf("%d",&b );
  a=fak(a,b);
  printf("%d",a );




  return 0;
}
