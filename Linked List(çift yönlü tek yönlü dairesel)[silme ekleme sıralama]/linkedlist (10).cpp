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
	FILE *dosya;
	
	dosya = fopen("test.dat","rb+");
	
	if (!dosya)
	{
		printf("Dosya Acilamadi "); 
		exit(0);
	}

	
	do{ 

	     if (ilk==NULL)
	     {
			ilk = (TLISTE*) malloc(1*sizeof(TLISTE));	
 		    fread(ilk,sizeof(TLISTE),1,dosya);
			ilk->sonraki = NULL;
			ilk->onceki = NULL;
			son = ilk;   
		 }
		 else
		 {
			son->sonraki = (TLISTE*) malloc(1*sizeof(TLISTE));	
			son->sonraki->onceki = son;
			son = son->sonraki;
    		fread(son,sizeof(TLISTE),1,dosya);
			son->sonraki = NULL;   
		 }
	
	} while (feof(dosya));
	
	
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

	fclose(dosya);
	getch();
	
	return 0; 
	
}
