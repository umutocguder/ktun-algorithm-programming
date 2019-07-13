#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int sayac=0, sonuc;
int rec(int sayi){
if (sayi>0) {
	return sayi%10+rec(sayi/10);
}
else
return 0;

}


int main()
{
		int sayi,sonuc=0,toplam=0;
		printf("Bir sayi giriniz:");
		scanf("%d",&sayi);
		rec(sayi);
		printf("%d\n",rec(sayi) );
	return 0;
}
