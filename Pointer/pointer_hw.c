//içerisindeki elemanları pointer kullanarak selection algosuyla tersten sırala.

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int array[20],i;
  for (i = 0; i < 20; i++) {
      array[i]=rand()% 100;
  }

  return 0;
}
