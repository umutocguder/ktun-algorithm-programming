#include "stdio.h"
unsigned short rec(unsigned short i,unsigned short mask,unsigned short mask2){
  if (mask2>=mask) {
    if (i!=mask) {
        mask<<=1;
        return rec(i,mask,mask2);
    }
    else
      return 1;
  }
}
int main(int argc, char const *argv[]) {
  unsigned short i,mask=1,mask2=1;
  scanf("%d",&i);
  if (rec(i,mask,mask2)==1) {
    printf("true\n" );
  }else
  printf("false");
  return 0;
}
