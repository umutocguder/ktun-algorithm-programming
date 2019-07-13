#include <stdio.h> 
#include <conio.h> 

int main () 
{ 
	int var[] = {10, 100, 200}; 
	
	int i, *ptr; 
	
	//ptr = var; // 
	ptr = &var[0];
	
	for ( i = 0; i < 3; i++) 
	{ 
		printf("Degisken var[%d] = %x\n", i, ptr ); 
		printf("Deger    var[%d] = %d\n", i, *ptr ); 
		
		ptr++; 
	}
	
	getch();
	
	return 0; 
	
}
