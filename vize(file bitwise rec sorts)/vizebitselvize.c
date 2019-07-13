/*16 bitlik bir değişken içerisine gün, ay ve 2000 yılından sonra
olmak üzere tarih bilgisi yerleştirilecektir. Bitsel işlemleri
kullanarak ekrandan girilen tarih bilgisini "short int" tipinde
16 bitlik değişken içerisine yerleştiren ve daha sonra bu bilgiyi
 çözümleyip ekrana yazan bir program yazınız.*/
#include "stdio.h"
void Goster(unsigned short sayi)
{	int i;
	unsigned short Maske=1<<15;
	printf("%u :",sayi);
	for(i=1;i<17;i++)
	{
		putchar(sayi&Maske? '1' : '0');
		sayi<<=1;
		if(i%4==0) putchar(' ');
	}
	printf("\n");
}
int main(int argc, char const *argv[]) {
  unsigned short a,mask=0,gun,ay,yil;
  scanf("%u",&gun);
  mask|=gun;
  Goster(mask);
  scanf("%u",&ay);
mask<<=4;
  return 0;
}
