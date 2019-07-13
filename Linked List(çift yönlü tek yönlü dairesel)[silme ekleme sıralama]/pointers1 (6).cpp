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
	// [--5 elemanlý ve ön tanýmlý--]
	
	ilk = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
	ptr = ilk;   // Tek Yönlü Baðlý Listede Ilk Eleman Asla Kaybedilmez!!!!

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
	ÖRNEK GÖSTERÝM
	+----+-+
   	|DATA|P|  -->
	+----+-+
	+ ADRES+
    
	Adres : ****f0 -> temsili ->2713f0

TEMSÝLÝ BAÐLI LÝSTE
+-----+------+        +-----+------+        +-----+------+        +-----+------+        +-----+------+
|50-80|271310| --->   |40-70|271330| --->   |30-70|271350| --->   |90-40|271370| --->   |70-50|NULL-0| --->
+-----+------+        +-----+------+        +-----+------+        +-----+------+        +-----+------+
+   2713f0   +        +   271310   +        +   271330   +        +   271350   +        +   271370   +


*/

	// [--LISTE GORUNTULE--]

	
	ptr = ilk;// Dongü için ilk elemana tekrar dön/ilk elemaný hala kaybetme.
	         
	while (ptr!=NULL)  // (!ptr)
	{  
		// O Anki Pointer'ýn Gösterdiði Elemaný Kullan
		printf("Vize[%d] Final[%d] Adres[%x]  =>  Sonraki[%x] \n",ptr->vize, ptr->final,ptr,ptr->sonraki); 		
		// Bir Sonraki Elemana Geç
		ptr=ptr->sonraki; 
	}
	
	// [--LISTE SIL--]

	
	ptr = ilk;
	
	while (ptr!=NULL)// Dongü için ilk elemana tekrar dön/ilk elemaný hala kaybetme.
	{  
		// Geçici bir pointer'a suanki elemaný ata
		gecici = ptr;
		// suanki eleman pointeri bir sonraki elemaný göstersin
		ptr    = ptr->sonraki;
		//gecici elemaný sil
		free(gecici);
	}

	
	getch();
	
	return 0; 
	
}
