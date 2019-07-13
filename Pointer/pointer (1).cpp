#include <stdio.h>
#include <conio.h>
#include <stdio.h>
int main ()
{
 int i,n;
 int *p;
 printf("Kac sayi gireceksiniz? ");
 scanf("%d",&i);
 p= new (nothrow) int[i];
 if (p == 0)
    printf("HATA!!! Hafiza tahsisi basarisiz oldu");ß
 else
 {
     for (n=0; n<i; n++)
     {
         printf("Sayilari giriniz: ");
         scanf("%d",(p+i));
     }

     printf("\n Girdiginiz sayilar: ");
     for (n=0; n<i; n++)
          printf("%d\n",p[n]);
     delete[] p;
 }
 return 0
}
