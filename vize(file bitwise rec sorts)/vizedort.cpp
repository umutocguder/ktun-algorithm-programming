#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

struct TOGRENCI {
	int vize;
	int final;
};


int main () 
{ 
	TOGRENCI *ilk;
	
	ilk = (TOGRENCI*) malloc(5*sizeof(TOGRENCI));

	ilk[0].vize  = 50;
	ilk[0].final = 80;
	ilk[1].vize  = 40;
	ilk[1].final = 70;
	ilk[2].vize  = 30;
	ilk[2].final = 70;
	ilk[3].vize  = 90;
	ilk[3].final = 40;
	ilk[4].vize  = 70;
	ilk[4].final = 50;

	 
	int i; 
	TOGRENCI  *ptr;
	
	ptr = ilk; 
	         
	for ( i = 0; i < 5; i++)    
	{  
		printf("Degisken var[%d] = %x   Deger    var[%d]=%d\n", i, ptr,i, ptr->vize);
		ptr++; 
	}
	
	free(ilk);
	
	getch();
	
	return 0; 
	
}
