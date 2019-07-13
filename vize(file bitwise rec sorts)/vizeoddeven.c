#include "stdio.h"
int main(int argc, char const *argv[]) {
  int a=9;
  int b=8;
a<<=31;
a>>=31;
b<<=31;
b>>=31;

  (a&1)? printf("odd"): printf("even");
  (b&1)? printf("odd"): printf("even");

  return 0;
}
