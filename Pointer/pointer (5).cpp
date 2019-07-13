#include <stdio.h> 
#include <conio.h> 

int main () 
{ 
	int var = 25; /* gercek degisken tanimi */ 
	int *ip;      /* pointer tanimi */ 
	
	int *ptest = NULL;

	ip = &var;    /* adres ataması - gercek degiskenin adresini pointer'a ata*/ 

	printf("Degiskenin adresi       : %x\n", &var );
	printf("Pointerda tutulan adres : %x\n", ip );  
	printf("Pointer'in degeri       : %d\n", *ip ); 
	
	// int *ip;      /* pointer tanimi */ 
	//     *ip;      /* pointer degeri */ 
	//      ip;      /* pointerda tutulan adres */ 
	
	
	printf("\n\n");  
	printf("Pointerda tutulan adres : %x\n", ptest );  
	
	if (ptest)   //   ptest NULL degilse <>
	   printf("Pointer'in degeri       : %d\n", *ptest ); 
	
	if (!ptest)  //   ptest NULL ise ==
	   printf("Pointer NULL'dur\n"); 
	
	getch();
	
	return 0; 
	
}
