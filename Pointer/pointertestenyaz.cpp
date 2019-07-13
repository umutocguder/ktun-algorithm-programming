#include<stdio.h>
#include<conio.h>
#include<string.h>


void tersYaz(char* metin, int uzunluk) 
{
  if (uzunluk >= 0) {
	printf("%c",metin[uzunluk]);
                  tersYaz(metin, uzunluk-1);     
  }  
}  

int main()
{
   char* kelime  = "123abc456";
   int uzunluk = strlen(kelime);
   tersYaz(kelime, uzunluk);
   getch();
   return 0;
}


