/*Başlangıçta dizinin ilk elemanını en büyükmüş gibi
kabul eden her döngü adımında dizideki en büyük değeri bulup
 ilk pozisyona aktararak ve diziyi sürekli bir sonraki elemandan
başlatıp dizi boyutunu azaltarak sıralayan*/
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
int main(int argc, char const *argv[]) {
  int array[10]={4,2,5,1};
  int i,j,k,eb=array[0];
  for (j = 0; j < 4; j++) {
    eb=array[0];
    for (i = j+1; i < 4; i++) {
      if (eb<array[i]) {
        eb=array[i];

      }
int temp =array[j];
array[j]=array[eb];
array[eb]=temp;
    }

  }

  for(i=0;i<4;i++)printf("%d\n",array[i] );
  return 0;
}

/*
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
int main(int argc, char const *argv[]) {
  int dizi[10],i,k,j,eb,ek;
  for (i = 0; i <10; i++) {
    dizi[i]=rand()%10;
  }

  for (i = 0; i <10; i++) {
    printf("%d\n", dizi[i]);
  }
  printf("\n" );
  eb=dizi[0];
  j=0;
  for (i = 0; i <10; i++) {
    if (eb<dizi[i]) {
      eb=dizi[i];
      }
      if (i==9) {
        dizi[j]=eb;
        j++;
        i=j;
        eb=dizi[j];
      }


  }
  for (i = 0; i <10; i++) {
    printf("%d\n", dizi[i]);
  }
  return 0;
}*/
