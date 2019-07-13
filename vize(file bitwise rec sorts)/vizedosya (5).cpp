#include <stdio.h>
#include <conio.h>
#include <string.h>

 struct TOgrenci{
	char ad[15];
	char soyad[15];
	int vize;
	int final;
	double ortalama;
} ogr;

int main()
{

	TOgrenci dizi[3];

	strcpy(dizi[0].ad,"d_ad");
	strcpy(dizi[0].soyad,"d_soyad");
	dizi[0].vize=70;
	dizi[0].final=90;

	strcpy(dizi[1].ad,"bilgi");
	strcpy(dizi[1].soyad,"sayar");
	dizi[1].vize=20;
	dizi[1].final=40;

	strcpy(dizi[2].ad,"selcuk");
	strcpy(dizi[2].soyad,"kampus");
	dizi[2].vize=60;
	dizi[2].final=70;

	int i;

	for (i=0;i<3;i++)
	{
		printf("Adi : %s   Soyadi : %s   Vize : %d   Final : %d\n",dizi[i].ad,dizi[i].soyad,dizi[i].vize,dizi[i].final);
	}

	getch();

	return 0;
}
