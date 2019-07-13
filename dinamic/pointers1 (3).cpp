#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

int main () 
{ 
	int *dizi;
	
	dizi = (int*) malloc(5*sizeof(int));

	dizi[0] = 50;
	dizi[1] = 150;
	dizi[2] = 75;
	dizi[3] = 100;
	dizi[4] = 200;

	int i, adet=5;
	
         
	printf("dizi    => Adres : %x ----------\n", dizi ); 		

	for ( i = 0; i < adet; i++)    
	{  
		printf("dizi[%d] => Adres : %x Deger : %d\n", i, &dizi[i],*dizi ); 		
	}

	printf("dizi    => Adres : %x ----------\n", dizi ); 		
	
	free(dizi);
	
	getch();
	
	return 0; 
	
}
