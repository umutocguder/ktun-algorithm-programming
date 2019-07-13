#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main() {
  int i,array[100],array2[100],j,k=0;
int count=0;
  FILE *mafile;
int counter=0;
  mafile = fopen("sayilar.txt","r");

for(i=0;i<100;i++){
fscanf(mafile,"%d",&array[i]);
printf("%d\tsayisi alindi\n",array[i] );
}
printf("DOSYA OKUNDU\n\n\n\n\n\n\n" );

for (i = 0; i < 100; i++) {
    counter=0;
    for (j = 2; j < array[i]; j++) {

      if (array[i]%j==0) {
        counter=1;
        }
      }

      if (counter==0) {
            array2[k]=array[i];
            k++;
    }
  }
  for ( i = 0; i <k; i++){
  printf("%d\t asal olarak islendi\n",array2[i]);
  }
  fclose(mafile);

  FILE *mafile2;
  mafile2=fopen("sayilar2.txt","a");
  if (mafile2==NULL) {
    printf("dosya yok");
  }
  else{
  for ( i = 0; i <k; i++){

    fprintf(mafile2,"%d\n",array2[i] );

  }
printf("YENI DOSYA OLUSTU\n" );
}
  fclose(mafile2);
  return 0;
}
