
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

int main(int argc, char const *argv[]) {
  FILE *dosya;
  FILE *dos;
  int i,j,k;
  int dizi[10],dizi2[10];
  dosya = fopen ("sayilar.txt","w");

for (i = 0; i < 4; i++) {
  fprintf(dosya,"%d",dizi[i]);
}
  dos =fopen("sayilar2.txt","w");
i=0;
  while (!feof(dosya)) {
    fscanf(dosya,"%d",&dizi2[i]);
    fprintf(dos, "%d",dizi2[i]);
    i++;
  }
  fclose(dos);

  fclose(dosya);
  return 0;
}











/*#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"
// 5 yada 8 e bölünüyosa 2.dosyaya yaz.
int main(int argc, char const *argv[]) {
  FILE *file;
  FILE *file2;
  int i,j,k,counter=0,array[100],array2[100],array3[100];
  srand(time(NULL));
file2=fopen("something2.txt","w+");
  file=fopen("something.txt","w+");
for ( i = 0; i < 100; i++) {
  fprintf(file,"%d\n",array[i]=rand()%100);
}
  fclose(file);

while (!feof(file)) {
  fscanf(file,"%d",&array2[i]);
  if (array2[i]>4) {
    if (array2[i]%5==0 ||array2[i]%8==0) {
        fprintf(file2, "%d\n",array2[i] );
        printf("%d\n",array2[i]);
      }
      i++;
    }
  }






  fclose(file2);
  return 0;
}
*/
