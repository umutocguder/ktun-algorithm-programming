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
	
	// ilk ifadesi en üst anlamýnda = top deðiþkeni ile kullanýlabilir
	
	// [--LISTE OLUSTUR--]
	// [--eleman sayisi dinamik--]  // STACK = YIÐIN
	
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

	printf("Devam için [1] : ");scanf("%d",&devam);
	
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


	// [--LISTE GORUNTULE--] KALAN KISIM BÝR ÖNCEKÝ ÖRNEKLE AYNI

	
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
