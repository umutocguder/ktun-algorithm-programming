  /*200 adet 4 bitlik sayiyi çözümle.*/
  #include "stdio.h"
  int main(int argc, char const *argv[]) {
    FILE *file ;
    int i,array[60];
    file =fopen("deneme.txt","r");
    for (i = 0; i < 200; i++) {
      for (i = 0; i <4; i++) {
        fscanf("%d",&array[i]);
      }
    }
    fclose (file);
    return 0;
  }
