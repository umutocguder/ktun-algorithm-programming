#include <stdio.h> 
#include <conio.h> 

int uzunluk(char *metin)
{
	int i=0;
	
	while (metin[i])
		i++;
	
	return i;
}

int main () 
{ 
	char *metin = "Bilgisayar Muhendisligi"; 
	
	int i=0;
	
	while (metin[i])
		{
			printf("Harf[%d] = %c \n", i, metin[i] ); 
			
			i++;
		}
	
	printf("------------------- \n", uzunluk(metin)); 
	printf("Uzunluk = %d \n", uzunluk(metin)); 

	
	getch();
	
	return 0; 
	
}


