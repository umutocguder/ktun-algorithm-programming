#include "stdio.h"
#include "stdlib.h"

unsigned short ters(unsigned short a){
  unsigned short maske=0;
  maske=~maske;
  a^=maske;
  return a ;
}

unsigned short onean(unsigned short a){
int i;
unsigned short mask=0;
for ( i = 0; i <8; i++) {
  mask+=1;
  mask<<=2;
  if (i==7) {
    mask+=1;
    mask<<=1;
  }
}
a&=mask;
  return a ;
}

unsigned short thirth(unsigned short a){
  unsigned short mask=1,mask2=1;
  //3.biti sıfırlayıp
  //011 le veleyince
  mask<<=2;
  mask =~mask;
  //printf("mask %u\n",mask );
  //5.biti 1le
//10000 la veyala
  mask2<<=4;
  //printf("mask2 %u\n",mask2 );
  a|=mask2;
  a&=mask;
  return a;
}
void bitlikgoster(unsigned short a)
{	int i;
	unsigned short Maske=1<<15;
	printf("%u :",a);
	for(i=1;i<17;i++)
	{
		putchar(a&Maske? '1' : '0');
		a<<=1;
		if(i%4==0) putchar(' ');
	}
	printf("\n");
}
void dosyayaat(unsigned short a){
FILE *file ;
file =fopen ("burda.txt","a");
fprintf(file, "%u",a );
fclose(file);
}
int main(int argc, char const *argv[]) {
//her elemanı ters çevir  bir 1 bir 0 gelen bi şeyle ve le sonra 3.bitini sıfırlayıp dosyaya at ....
unsigned short a ;
printf( "enter an unsigned short");
scanf(" %u",&a );
printf("sayinin kendisi\n" );
bitlikgoster(a);
a=ters(a)  ;
printf("ters hali\n");
bitlikgoster(a );
a=onean(a);
printf("1ve 0 larla veleyince \n" );
bitlikgoster(a);
a=thirth(a);
printf("3. bitini sıfırlayınca 5. bitini birleyince\n" );
bitlikgoster(a);
dosyayaat(a);
printf("dosyaya atandı\n" );
return 0;
}
