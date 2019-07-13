#include <windows.h>
#include <stdio.h>
#include <conio.h>
 struct TOgrenci{
	char ad[15];
	char soyad[15];
	int vize;
	int final;
	double ortalama;
} ogr;

	
int Ekle(FILE *dosya)
{
	system("cls");
	
	printf("konum : %d   \n\n",ftell(dosya));
	
	printf("Adý :");	 scanf("%s",ogr.ad);
	printf("Soyadý :");	 scanf("%s",ogr.soyad);
	printf("Vize :");	 scanf("%d",&ogr.vize);
	printf("Final :");	 scanf("%d",&ogr.final);
	printf("Ortalama :");scanf("%f",&ogr.ortalama);
	
	printf("\n");
	
	fwrite(&ogr,sizeof(ogr),1, dosya);
	
	getch();
	
	return (0);	
}

int Oku(FILE *dosya)
{
	printf("konum : %d   \t",ftell(dosya));
	
	fread(&ogr,sizeof(ogr),1, dosya);
	
	printf("Adý : %s\t",ogr.ad);
	printf("Soyadý : %s\t",ogr.soyad);
	printf("Vize : %d\t",ogr.vize);
	printf("Final : %d\t",ogr.final);
	printf("Ortalama : %3.2f\n",ogr.ortalama);
	
	printf("\n");
		

	
	return (0);
}

int Listele(FILE *dosya)
{
	system("cls");
	
	fseek(dosya,0,SEEK_SET);
	//rewind();
	//fseek(dosya,1*sizeof(ogr),SEEK_SET); // SEEK_CUR , SEEK_END
	
	while (!feof(dosya))
	{
		Oku(dosya);
	}
	
	getch();		
}

int Bul(FILE *dosya)
{
	system("cls");
	
	char aranan[15];
	
	printf("Aranan isim : ");
	scanf("%s",aranan);
	
	fseek(dosya,0,SEEK_SET);
	//rewind();
	//fseek(dosya,1*sizeof(ogr),SEEK_SET); // SEEK_CUR , SEEK_END
	
	while (!feof(dosya))
	{
		fread(&ogr,sizeof(ogr),1, dosya);
		
		if (strcmp(aranan,ogr.ad)==0)
		{
		
			printf("Adý : %s\t",ogr.ad);
			printf("Soyadý : %s\t",ogr.soyad);
			printf("Vize : %d\t",ogr.vize);
			printf("Final : %d\t",ogr.final);
			printf("Ortalama : %3.2f\n",ogr.ortalama);
			
			printf("\n");
			break;
		}
	}
	
	getch();
	
	return (0);			
}

int Git(FILE *dosya)
{
	system("cls");
	
	int aranan;
	
	printf("Aranan kayýt no : ");
	scanf("%d",&aranan);
	
	fseek(dosya,(aranan-1)*sizeof(ogr),SEEK_SET);
	
	Oku(dosya);
	
	getch();
	
	return (0);			
}


int main(int argc, char **argv)
{
	
	FILE *dosya;
	
	dosya = fopen("deneme.dat", "a+");
	
	if (dosya==NULL)
	{
		printf("deneme.dat dosyasi acilamadi\n");
		return -1;
	}
	else
	{
		
		int secim = 1;
		
		while ((secim>0)&&(secim<5) )
		{
			printf("0. Cikis \n");
			printf("1. Kayit Ekle \n");
			printf("2. Kayit Bul \n");
			printf("3. Kayit No ile Goster \n");
			printf("4. Kayit Listele \n");
			printf("Seçiminizi Yapiniz : ");
			scanf("%d",&secim);	
			fflush(stdin);
		
			switch(secim){
				
				case 1 : {
							Ekle(dosya);							
							fflush(stdin);
					break;
				}

				case 2 : {
							Bul(dosya);
							fflush(stdin);
					break;
				}

				case 3 : {
							Git(dosya);
							fflush(stdin);
					break;
				}
				case 4 : {
							Listele(dosya);							
							fflush(stdin);
					break;
				}
				
			}
		
		
		}
		
		fclose(dosya);
	
		return 0;
		
	}
	
}

//rename("eski.txt", "yeni.txt");
//remove("deneme.txt");

