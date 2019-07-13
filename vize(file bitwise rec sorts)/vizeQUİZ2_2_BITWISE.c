#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//65535
int solakaydir(unsigned sayi,int k){
	int i,a=0;
	for(i=0;i<k;i++){
		a=sayi>>15;
		if(a==1){
			sayi<<=1;
sayi|=1;
		}
		else{
			sayi<<=1;
		}
	}
return(sayi);
}
void Goster(unsigned sayi)
{	int i;
	unsigned Maske=1<<15;
	printf("%u :",sayi);
	for(i=1;i<17;i++)
	{
		putchar(sayi&Maske? '1' : '0');
		sayi<<=1;
		if(i%4==0) putchar(' ');
	}
	printf("\n");
}

int main (){
	unsigned a,c;
	int b;
	printf("Deger giriniz:");
	scanf("%u",&a);
	printf("Kaydirma adeti giriniz:");
	scanf("%d",&b);
	Goster(a);
	c=solakaydir(a,b);

	Goster(c);
		printf("%d",c );
}
