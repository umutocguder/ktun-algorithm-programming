#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

int main () 
{ 
	int *var;
	
	var = (int*) malloc(5*sizeof(int));
	//var = new int[5];  //C++

	var[0] = 50;
	var[1] = 150;
	var[2] = 75;
	var[3] = 100;
	var[4] = 200;

	//  new => malloc
	//  calloc (zero initalizes buffer)
	//  var = (int*) calloc(5,sizeof(int));
	//  realloc 
	//  free

	 
	int i, *ptr; 
	
	ptr = var; 
	         
	for ( i = 0; i < 5; i++)    
	{  
		printf("Degisken var[%d] = %x   Deger    var[%d]=%d\n", i, ptr,i,*ptr ); 		
		ptr++; 
	}
	
	free(var);
	//delete[] var; //C++
	
	getch();
	
	return 0; 
	
}
