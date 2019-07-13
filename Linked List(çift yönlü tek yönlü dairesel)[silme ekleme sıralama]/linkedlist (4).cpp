#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

struct TOGRENCI {
	int deger;
	struct TOGRENCI *sonraki;
/**/struct TOGRENCI *onceki;	
};

int main () 
{ 
	TOGRENCI *ilk=NULL, *ptr=NULL, *gecici=NULL, *bul;
	int devam=1;
	
	// [--LISTE OLUSTUR--]
	// [--eleman sayisi dinamik--]   SIRALI LISTE
	
	do{ 
	     if (ilk==NULL)
	     {
			ilk = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
			printf("Deger  : ");scanf("%d",&ilk->deger);
			ilk->sonraki = NULL;
/**/        ilk->onceki = NULL;
		 }
		 else
		 {			
			// eleman� olu�tur
			gecici = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));				
			printf("Deger  : ");scanf("%d",&gecici->deger);
			gecici->sonraki = NULL;
/**/		gecici->onceki = NULL;

			ptr = ilk;
			
			// Kaydilece�i Yeri Belirle
			while (ptr!=NULL)
			{
			    if (ptr->deger > gecici->deger)
				   ptr = ptr->sonraki;
				else
			       break;
			}
			//  9{gecici}
			// 21 15 10 8{ptr} 6 2
			
			
			//E�er sonda ise sona ekle
			if (ptr==NULL)
			{
				//sondan bir �nceki elemana git				
				ptr=ilk; 
				while (ptr->sonraki!=NULL) 
				{
					ptr=ptr->sonraki;
				}
				
				ptr->sonraki = gecici;
/**/			gecici->onceki = ptr;
				gecici = NULL;
			
			}
			else if (ptr==ilk)
			{
				gecici->sonraki=ptr;
/**/			ptr->onceki=gecici;				
				ilk=gecici;
				gecici=NULL;
			}
			//E�er arada ise araya ekle
			else
			{
			//  9{gecici}
			// 21 15 10 8{ptr} 6 2

/**/			gecici->sonraki = ptr;
/**/			gecici->onceki  = ptr->onceki;
/**/			ptr->onceki->sonraki = gecici;
/**/			ptr->onceki = gecici;
				gecici=NULL;
				
			}
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
/**/	printf("Deger[%d] Adres[%x]  =>  Sonraki[%x] Onceki[%x] \n",ptr->deger, ptr,ptr->sonraki,ptr->onceki); 		
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
