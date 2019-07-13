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
	//dizi = (int*) malloc(5*sizeof(int));

	ilk[0].vize  = 50;	ilk[0].final = 80;
	ilk[1].vize  = 40;	ilk[1].final = 70;
	ilk[2].vize  = 30;	ilk[2].final = 70;
	ilk[3].vize  = 90;	ilk[3].final = 40;
	ilk[4].vize  = 70;	ilk[4].final = 50;

	 
	int i, adet=5; 
	
	printf("dizi    => Adres : %x -------------------------\n", ilk ); 		

	for ( i = 0; i < adet; i++)    
	{  
		printf("dizi[%d] => Adres : %x DegerV : %d  DegerF : %d\n", i, &ilk[i], ilk[i].vize, ilk[i].final); 		
	}

	printf("dizi    => Adres : %x -------------------------\n", ilk ); 		
	
	free(ilk);
	
	getch();
	
	return 0; 
	
}
