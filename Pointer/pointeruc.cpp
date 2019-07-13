#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>
#include <string.h>


int main()
{
   char *str;

   /* Initial memory allocation */
   str = (char *) malloc(14);
   strcpy(str, "Merhaba Selcuk");
   printf("Adres = %u , Metin = %s\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, " Bilgisayar");
   printf("Addes = %u , Metin = %s\n", str, str);

   free(str);
   
   return(0);
}
