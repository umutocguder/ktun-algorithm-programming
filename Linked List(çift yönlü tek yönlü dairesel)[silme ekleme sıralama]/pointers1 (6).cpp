#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

struct TOGRENCI {
	int vize;
	int final;
	struct TOGRENCI *sonraki;
};


int main () 
{ 
	TOGRENCI *ilk, *ptr, *gecici;
	
	// [--LISTE OLUSTUR--]
	// [--5 elemanl� ve �n tan�ml�--]
	
	ilk = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
	ptr = ilk;   // Tek Y�nl� Ba�l� Listede Ilk Eleman Asla Kaybedilmez!!!!

	ptr->vize    = 50;
	ptr->final   = 80;
	ptr->sonraki = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));
	ptr          = ptr->sonraki;

	ptr->vize    = 40;
	ptr->final   = 70;
	ptr->sonraki = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));
	ptr          = ptr->sonraki;

	ptr->vize    = 30;
	ptr->final   = 70;
	ptr->sonraki = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));
	ptr          = ptr->sonraki;

	ptr->vize    = 90;
	ptr->final   = 40;
	ptr->sonraki = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));
	ptr          = ptr->sonraki;

	ptr->vize    = 70;
	ptr->final   = 50;
	ptr->sonraki = NULL;

/*
	�RNEK G�STER�M
	+----+-+
   	|DATA|P|  -->
	+----+-+
	+ ADRES+
    
	Adres : ****f0 -> temsili ->2713f0

TEMS�L� BA�LI L�STE
+-----+------+        +-----+------+        +-----+------+        +-----+------+        +-----+------+
|50-80|271310| --->   |40-70|271330| --->   |30-70|271350| --->   |90-40|271370| --->   |70-50|NULL-0| --->
+-----+------+        +-----+------+        +-----+------+        +-----+------+        +-----+------+
+   2713f0   +        +   271310   +        +   271330   +        +   271350   +        +   271370   +


*/

	// [--LISTE GORUNTULE--]

	
	ptr = ilk;// Dong� i�in ilk elemana tekrar d�n/ilk eleman� hala kaybetme.
	         
	while (ptr!=NULL)  // (!ptr)
	{  
		// O Anki Pointer'�n G�sterdi�i Eleman� Kullan
		printf("Vize[%d] Final[%d] Adres[%x]  =>  Sonraki[%x] \n",ptr->vize, ptr->final,ptr,ptr->sonraki); 		
		// Bir Sonraki Elemana Ge�
		ptr=ptr->sonraki; 
	}
	
	// [--LISTE SIL--]

	
	ptr = ilk;
	
	while (ptr!=NULL)// Dong� i�in ilk elemana tekrar d�n/ilk eleman� hala kaybetme.
	{  
		// Ge�ici bir pointer'a suanki eleman� ata
		gecici = ptr;
		// suanki eleman pointeri bir sonraki eleman� g�stersin
		ptr    = ptr->sonraki;
		//gecici eleman� sil
		free(gecici);
	}

	
	getch();
	
	return 0; 
	
}
