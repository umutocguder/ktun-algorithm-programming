#include <stdio.h> 
#include <conio.h> 

int main () 
{ 
	int var[] = {10, 100, 200}; 
	
	//int i, *ptr; 
	int i, *ptr[3]; 
	
	//ptr = var; 
	for (i=0;i<3;i++)
	{
		ptr[i]=&var[i];
	}
	
	
	for ( i = 0; i < 3; i++) 
	{ 
		printf("Degisken var[%d] = %x\n", i, ptr[i] ); 
		printf("Deger    var[%d] = %d\n", i, *ptr[i] ); 
		
		//ptr++; 
	}
	
	getch();
	
	return 0; 
	
}
