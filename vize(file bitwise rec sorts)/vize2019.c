/*
1.left shift kere kaydir
2.dizi oluştur indisi çift olanları insertion ile ters sırala tekleri selection ile duz sırala
3.sayilar.txt deki 100 sayiyi al quickle sıralayıp sirali.txt ye at.
4.asal sayi recursive fonksiyonu
5.0-256 arasinda int al unsigned inte sırayla yazdir...

*/
//1
/*
#include "stdio.h"

int fonks(unsigned short sayi , int k)
{
  return;
}

int main(int argc, char const *argv[]) {
int maske=1;


  return 0;
}*/
//4
/*
#include "stdio.h"
int asal(int sayi,int counter, int i){
if(i<sayi){
  if(sayi%i==0){
    return 0;
  }
  else{
    asal(sayi,0,i+1);
  }
}
else
  return 1;
}

int main(int argc, char const *argv[]) {
  int sayi,i,j;
  printf("sayi giriniz \n" );
  scanf("%d",&sayi);
  if (asal(sayi,0,2)==0) {
    printf("asal degil\n" );
  }
  else
  printf("asaldir\n");
  return 0;
}*/

//3
/*
#include "stdio.h"
int main(int argc, char const *argv[]) {
FILE *dosya ;
FILE *dosya2;
int dizi[100],i;
dosya = fopen("sayilar.txt","r");

dosya2 =fopen ("sirali.txt","w");
for(i=0;i<100;i++){
  fscanf(dosya,"%d",&dizi[i]);
}
quick(dizi,i);
partition(dizi,i);
for(i=0;i<100;i++){
  fprintf(dosya2 , "%d\n",dizi[i]);
}



fclose(dosya);
fclose(dosya2);
  return 0;
}
*/
/*
//2
#include "stdio.h"
int selectionduz(){


}
int main(int argc, char const *argv[]) {

  return 0;
}*/
/*
//5
#include "stdio.h"
int main(int argc, char const *argv[]) {
int a,sayi,i;
unsigned int mask=0;

  for(i=0;i<4;i++){
    printf("sayi gir\n" );
    scanf("%d",&sayi );
if (sayi>=0 && sayi<255) {
    mask|=sayi;
    mask<<=8;
}
else printf("hata bidaha dene" );
}printf("%d",mask );
  return 0;
}
*/
