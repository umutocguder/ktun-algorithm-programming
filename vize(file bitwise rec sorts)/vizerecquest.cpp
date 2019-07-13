#include <stdio.h>
#include <conio.h>


void rec(int a,int b)
{	int i=0;
	for (i=0;i<a;i++)printf("*");
	printf("\n");
	if (a<b) 
		rec(a+1,b);
	for (i=0;i<a;i++)printf("*");
	printf("\n");
}

int main()
{
	int b;
	 while(1==1)
	{
	printf("Recursive Ucgen Cizme\n");
	printf("Bir sayi giriniz:");
	scanf("%d",&b);	
	rec(1,b);
	printf("\n\n\n");	
	}
	
	getch();
	return 0;
}
