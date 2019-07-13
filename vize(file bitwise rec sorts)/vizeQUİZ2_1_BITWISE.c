#include<stdio.h>
#include <time.h>
#include <stdlib.h>
/*2.rasgele oluşturduğunuz 100 sayıdan 5. bitleri 0 olan sayıların 4. bitini 1 yaparak sayilar0.txt
dosyasına 5. bitleri 1 olan sayıların 3. bitini 0 yaparak 1.txt dosyasına yazan program kodunu yazınız.*/
int main(int argc, char const *argv[]) {
FILE	*dosya;
FILE 	*dosya2;
int i,array[i];
unsigned a=1,b=1,c=1,mask;
a<<=2;
b<<=3;
c=~c;
srand (time (NULL));
for (i = 0; i < 100; i++) {
	array[i]=rand()%100;
	mask=array[i];
	mask<<10;
	mask>>15;
	if (mask==1) {
	array[i]|=a;
	dosya=fopen("a.txt","w");
	fprintf(dosya, "%d\n",array[i]);
	fclose(dosya);
	}
	else{
	array[i]|=b;
	dosya2=fopen("b.txt","w");
	fprintf(dosya2, "%d\n",array[i]);
	fclose(dosya2);
	}
}
	return 0;
}
