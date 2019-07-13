#include "stdio.h"
#include "stdlib.h"
int main(){
FILE *file ;
FILE *file2 ;
int i,j;
char a[100];
char array[100][100];
file = fopen("acata.txt","w");
for (i = 0; i < 3; i++) {
  for (j = 0; j < 3; j++) {
  scanf("%s",&a);
  fprintf(file,"%s",a );
  }
}
fclose(file);
file =fopen("acata.txt","r");
file2 = fopen ("yazili.txt "," w");
for ( i = 0;!feof(file); i++) {
  fscanf(file,"%s",&a);
  fprintf(file2 ,"%s\n",a);
  printf("%s\n",a);
}
fclose (file );
fclose(file2);
  return 0;
}
