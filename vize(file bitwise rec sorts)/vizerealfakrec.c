#include "stdio.h"
int fuck(int a){

if (a<=1) {
  return 1;
}
else{
  return a*fuck(a-1);
}
}

int main(int argc, char const *argv[]) {
int a;
  printf(" faktoruyeli alincak bir sayi giriniz \n" );
  scanf("%d",&a );
  a=fuck(a );
  printf("%d", a );
  return 0;
}
