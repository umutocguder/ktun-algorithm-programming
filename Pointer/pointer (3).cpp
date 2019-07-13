#include <stdio.h> 
#include <conio.h> 

int main () 
{ 
	int Sayi=10; 
	char Metin[10] = "Denemedir";
	double Deger=3.14;

	printf("Sayi degiskeninin adresi  : %x  degeri : %d\n", &Sayi , Sayi); 
	printf("Metin degiskeninin adresi : %x  degeri : %s\n", &Metin, Metin); 
	printf("Deger degiskeninin adresi : %x  degeri : %f\n", &Deger, Deger); 

	// Pointer tanımları
	int *pSayi;
	char *pMetin;
	double *pDeger;


	getch();

	return 0; 
}
