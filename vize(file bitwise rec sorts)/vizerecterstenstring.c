#include "stdio.h"
int uzunluk(char kelime[],int i,int c) {
  if (kelime[i]!='\0') {
    return uzunluk(kelime,i+1,c+1);
  }
  else
  return c;
}
char tersten(char kelime[],int i,char kelime2,int c) {
  if (kelime[i]!='\0') {
    tersten(kelime,c-1,kelime2,c-1);
  }
  else{
    return kelime2;
  }
}

int main(int argc, char const *argv[]) {
  int i=0,c=0;
  char kelime[20],kelime2[20];
  gets(kelime);
  c=uzunluk(kelime,i,c);
  printf("%d uzunluk\n", c);
  printf("%s\n",kelime);

  printf("%s\n",tersten(kelime,i,kelime2,c));
  return 0;
}
