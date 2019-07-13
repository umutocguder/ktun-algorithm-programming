/*Kendisine parametre olarak gelen ve içerisinde 400 adet tam sayı bulunan bir dizi içerisinde, yine parametre olarak gelen bir
 tam sayıdan art arda 3 defa tekrar edecek şekilde kaç tane bulunduğunu bulan özyinelemeli bir fonksiyon yazınız.*/
 #include "stdio.h"
 int rec(int dizi[],int boyut,int tam,int j){
   if (boyut>=j) {
     if (dizi[j]==dizi[j+1]&&dizi[j+1]==dizi[j+2]) {
       return (dizi,boyut,tam,j+1)+1;
     }
     else
        return (dizi,boyut,tam,j+1);
      }
   }

 int main(int argc, char const *argv[]) {
   int i,dizi[400],tam,sonuc,j=0;
   for (i = 0; i < 4; i++) {
     printf("sayi giriniz");
     scanf("%d",&dizi[i]);
   }
   printf("bir tam sayi girniz\n");
   scanf("%d",&tam);
   printf("%d tane benzer sonuc bulunmustur\n",rec(dizi,i,tam,j));
   return 0;
 }

/*
 #include "stdio.h"
 int rec (int dizi[],int i,int tam,int j){
   while (j<i) {
     if (dizi[j]==tam&&dizi[j+1]==tam&&dizi[j+2]==tam) {
       return 1+rec(dizi,i,tam,j+1);
     }
     else{
         return rec(dizi,i,tam,j+1);
     }
   }

}
 int main(int argc, char const *argv[]) {
   int i,dizi[400],tam,sonuc,j=0;
   for (i = 0; i < 4; i++) {
     printf("sayi giriniz");
     scanf("%d",&dizi[i]);
   }
   printf("bir tam sayi girniz\n");
   scanf("%d",&tam);
   printf("%d tane benzer sonuc bulunmustur\n",rec(dizi,i,tam,j));
   return 0;
 }
*/
