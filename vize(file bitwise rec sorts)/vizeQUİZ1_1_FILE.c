#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main() {
  FILE *file1;
  int i,dizi[100];
  srand(time(NULL));
  file1 = fopen("sayilar.txt","w");
for (i = 0; i < 100; i++){
dizi[i]=rand() % 1000;
fprintf(file1, "%d\n",dizi[i]);
}
  fclose(file1);
    printf("dosya sorusu okey");
  return 0;
    
}
