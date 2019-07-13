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
	TOGRENCI *ilk=NULL, *ptr=NULL, *gecici=NULL;
	int devam=1;
	
	// ilk ifadesi en �st anlam�nda = top de�i�keni ile kullan�labilir
	
	// [--LISTE OLUSTUR--]
	// [--eleman sayisi dinamik--]  // STACK = YI�IN
	
	do{ 
	     if (ilk==NULL)
	     {
			ilk = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
			printf("Vize  : ");scanf("%d",&ilk->vize);
			printf("Final : ");scanf("%d",&ilk->final);
			ilk->sonraki = NULL;
		 }
		 else
		 {
			ptr = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
			ptr->sonraki = ilk;
			printf("Vize  : ");scanf("%d",&ptr->vize);
			printf("Final : ");scanf("%d",&ptr->final);
			ilk = ptr;
		 }

	printf("Devam i�in [1] : ");scanf("%d",&devam);
	
	} while (devam==1);
	
	
	// [--LISTE SAYISI--]

	ptr = ilk;
	int say = 0;
	         
	while (ptr!=NULL)  // (!ptr)
	{  
		ptr=ptr->sonraki; 
		say++;
	}

	printf("\nToplam Kuyruk Uzunlugu %d\n\n",say);


	// [--LISTE GORUNTULE--] KALAN KISIM B�R �NCEK� �RNEKLE AYNI

	
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
