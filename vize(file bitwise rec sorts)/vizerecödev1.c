#include "stdio.h"
int rec(int a){
if (a>=1) {
  return a+rec(a-1);
}
else{
  return 0;
}
}
int main(int argc, char const *argv[]) {
  int a ;
  printf("sayi giriniz \n" );
  scanf("%d",&a );
  a=rec(a);
  printf("o sayiya kadar toplam%d",a);
  return 0;
}
