//The Binary value of decimal no. 66 is : 1000010
#include "stdio.h"
int rec(int number,int i) {
  if (i<33) {
    int mask =1,masknum;
    masknum=number;
    masknum>>=i;
    if (mask==masknum) {
      printf("%d",1);
    }
    else
    printf("%d",0);
  }
  return rec(number,i+1);
  }
int main(int argc, char const *argv[]) {
  int a;
  scanf("%d",&a);
  rec(a,0);
  return 0;
}
