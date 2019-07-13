#include "stdio.h"

int obeb(int a,int b){

  if (b==0) {
    return a;
  }

  else {
    return obeb(b,a%b);
  }

}

int main(int argc, char const *argv[]) {

    int a ,b;

  printf("sayi giriniz \n" );
  scanf("%d",&a);
  printf("sayi giriniz \n" );
  scanf("%d",&b);

  a=obeb(a,b);

  printf("%d",a);
  return 0;

}
