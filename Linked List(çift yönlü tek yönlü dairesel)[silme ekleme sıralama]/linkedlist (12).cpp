#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

struct TDERS {
	int vize;
	int final;
};

struct TLISTE {
	int vize;
	int final;
	struct TLISTE *sonraki;
    struct TLISTE *onceki;
};

int main () 
{ 
	TLISTE *ilk=NULL, *son=NULL, *ptr=NULL, *gecici=NULL;
	FILE *dosya;
	struct TDERS ders;
	
	dosya = fopen("test.dat","ab+");
	
	if (!dosya)
	{
		printf("Dosya Acilamadi "); 
		exit(0);
	}


	int devam=1;
	
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
	

	
	ptr = ilk;
	         
	while (ptr!=NULL)  // (!ptr)
	{  
  		printf("Deger[%d] Adres[%x]  =>  Sonraki[%x] Onceki[%x]\n",ptr->deger, ptr, ptr->sonraki,ptr->onceki); 		
		ptr=ptr->sonraki; 
		
		fwrite(ptr,sizeof(TLISTE),1,dosya);
		
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

	fclose(dosya);
	getch();
	
	return 0; 
	
}
