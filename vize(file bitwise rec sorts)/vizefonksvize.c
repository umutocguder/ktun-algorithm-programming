/*Sadece bu fonksiyonları kullanarak kendisine parametre olarak verilen iki tamsayının en büyük ortak bölenini (EBOB) bulan fon*/
#include "stdio.h"
int topla(int a,int b){
  return a+b;
}
int cikar(int a,int b){
  return a-b;
}
int carp(int a,int b){
  return a*b;
}
float bol(int a,int b){

  return (float)a/b;
}
void ebob(int a,int b) {
int k,i,sonuc=1;
  if (cikar(a,b)>0)
  k=b;
  else
  k=a;
    for (i = 2; i <= k; i++) {
        if (a%i==0) {
          sonuc=carp(sonuc,i);
          a=bol(a,i);

        }
        if (b%i==0) {
          sonuc=carp(sonuc,i);
          b=bol(b,i);
        }

    }
    printf("%d",sonuc);
}
int main(int argc, char const *argv[]) {
  int a,b;
  printf("ilk a\n");
  scanf("%d",&a);
  printf("ikinci a\n");
  scanf("%d",&b);
  ebob(a,b);
  return 0;
}
