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
	
	ilk = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));
	ptr = ilk;

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

	
	ptr = ilk;
	         
	while (ptr!=NULL)  // (!ptr)
	{  
		printf("Degisken var = %x   Deger    var=%d\n", ptr, ptr->vize);
		ptr=ptr->sonraki; 
	}
	
	ptr = ilk;
	
	while (ptr!=NULL)
	{  
		gecici = ptr;
		ptr    = ptr->sonraki;
		free(gecici);
	}

	
	getch();
	
	return 0; 
	
}
