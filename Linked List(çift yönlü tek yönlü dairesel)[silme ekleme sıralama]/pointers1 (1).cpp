#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

struct TOGRENCI {
	int deger;
	struct TOGRENCI *sonraki;
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
		 }
		 else
		 {			
			// elemaný oluþtur
			gecici = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));				
			printf("Deger  : ");scanf("%d",&gecici->deger);
			gecici->sonraki = NULL;

			ptr = ilk;
			
			// Kaydileceði Yeri Belirle
			while (ptr!=NULL)
			{
			    if (ptr->deger > gecici->deger)
				   ptr = ptr->sonraki;
				else
			       break;
			}
			
			//Eðer sonda ise sona ekle
			if (ptr==NULL)
			{
				//sondan bir önceki elemana git				
				ptr=ilk; 
				while (ptr->sonraki!=NULL) 
				{
					ptr=ptr->sonraki;
				}
				
				ptr->sonraki = gecici;
				gecici = NULL;
			
			}
			else if (ptr==ilk)
			{
				gecici->sonraki=ptr;
				ilk=gecici;
				gecici=NULL;
			}
			//Eðer arada ise araya ekle
			else
			{
				bul=ilk; 
				while (bul->sonraki!=ptr) 
				{
					bul=bul->sonraki;
					if (bul==ilk)
						break;
				}
				
				bul->sonraki=gecici;
				gecici->sonraki=ptr;
				gecici=NULL;
				bul=NULL;
			}
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
		printf("Deger[%d] Adres[%x]  =>  Sonraki[%x] \n",ptr->deger, ptr,ptr->sonraki); 		
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
