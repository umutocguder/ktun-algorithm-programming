#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

struct TLISTE {
	int deger;
	struct TLISTE *sonraki;
    struct TLISTE *onceki;
};


int main () 
{ 
	TLISTE *ilk=NULL, *son=NULL, *ptr=NULL, *gecici=NULL;
	int devam=1;
	
	// [--LISTE OLUSTUR--]
	// [--eleman sayisi dinamik--]  
	
	do{ 
	     if (ilk==NULL)
	     {
			ilk = (TLISTE*) malloc(1*sizeof(TLISTE));	
			printf("Deger : ");scanf("%d",&ilk->deger);
			ilk->sonraki = NULL;
			ilk->onceki = NULL;
			son = ilk;   
		 }
		 else
		 {
			if (devam==1)
				{
					son->sonraki = (TLISTE*) malloc(1*sizeof(TLISTE));	
					son->sonraki->onceki = son;
					son = son->sonraki;
					printf("Deger : ");scanf("%d",&son->deger);
					son->sonraki = NULL;   
				}
			else if (devam==2)
				{
					ilk->onceki = (TLISTE*) malloc(1*sizeof(TLISTE));	
					ilk->onceki->sonraki = ilk;
					ilk = ilk->onceki;
					printf("Deger : ");scanf("%d",&ilk->deger);
					ilk->onceki = NULL;   
				}
		 }

	printf("Devam Sona Ekle [1] / Basa Ekle [2] : ");scanf("%d",&devam);
	
	} while ((devam==1)||(devam==2));
	
	
	// [--LISTE SAYISI--]

	ptr = ilk;
	int say = 0;
	         
	while (ptr!=NULL)  // (!ptr)
	{  
		ptr=ptr->sonraki; 
		say++;
	}

	printf("\nToplam Kuyruk Uzunlugu %d\n\n",say);

	
	ptr = ilk;
	         
	while (ptr!=NULL)  // (!ptr)
	{  
  		printf("Deger[%d] Adres[%x]  =>  Sonraki[%x] Onceki[%x]\n",ptr->deger, ptr, ptr->sonraki,ptr->onceki); 		
		ptr=ptr->sonraki; 
	}
	

	// [--LISTE SIL--]

	ptr = ilk;
	
	while (ptr->sonraki!=NULL)// Dongü için ilk elemana tekrar dön/ilk elemaný hala kaybetme.
	{  
		ptr = ptr->sonraki;
		free(ptr->onceki);
		ptr->onceki=NULL;
	}

	free(ptr);

	
	getch();
	
	return 0; 
	
}
