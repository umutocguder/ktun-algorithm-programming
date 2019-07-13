#include <stdio.h> 
#include <conio.h> 

int main () 
{ 
	char *names[] = {"Zara Ali", "Hina Ali", "Nuha Ali", "Sara Ali"}; 
	
	int i = 0; 
	
	for ( i = 0; i < 4; i++) 
	{ 
		printf("Isim[%d] = %s\n", i, names[i] ); 
	}	
	
	getch();
	
	return 0; 
	
}


