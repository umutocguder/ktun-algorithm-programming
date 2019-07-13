// 5. biti 0 olanları oluşturacağınız bir dizi içerisine pointer
//kullanarak aktar.

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int array[100],i,*array2,j=0,size=0;
  int *p=array;
  int mask=1;
  mask<<=4;
  for (i = 0; i < 3; i++) {
    scanf("%d",&array[i]);
  }
  for (i = 0; i < 3; i++) {

    mask&=array[i];
    if (mask==0) {
      size++;
      array2 = realloc(array,size*sizeof(int));
      *(array+size-1) = array[i];

    }
  }
  for (i = 0; i < size; i++) {
    printf("%d\n",*(array2+i));
  }

  return 0;
}
