#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>

struct TOGRENCI {
	int deger;
	struct TOGRENCI *sonraki;
	struct TOGRENCI *onceki;
};

TOGRENCI *sonaEkle(TOGRENCI *ilk, int dg)
{
	TOGRENCI *gecici;
	
	if (ilk==NULL)
	{
		ilk = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
		ilk->deger   = dg;
		ilk->sonraki = NULL;
/**/	ilk->onceki = NULL;
	}
	else
	{
		gecici = ilk;
		
		while (gecici->sonraki!=NULL)
		{
			gecici = gecici->sonraki;
		}
		
		gecici->sonraki = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
/**/	gecici->sonraki->onceki = gecici;
		gecici = gecici->sonraki;
		gecici->deger   = dg;
		gecici->sonraki = NULL;
	}
	
	return ilk;
}

TOGRENCI *basaEkle(TOGRENCI *ilk, int dg)
{
	TOGRENCI *gecici;
	
	if (ilk==NULL)
	{
		ilk = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
		ilk->deger   = dg;
		ilk->sonraki = NULL;
/**/	ilk->onceki = NULL;
	}
	else
	{
		gecici = ilk;
		
		//zaten ilk, tekrar baþa
		while (gecici->onceki!=NULL)
		{
			gecici = gecici->onceki;
		}
		
		gecici->onceki = (TOGRENCI*) malloc(1*sizeof(TOGRENCI));	
/**/	gecici->onceki->sonraki = gecici;
		gecici = gecici->onceki;
		gecici->deger   = dg;
		gecici->onceki = NULL;
		
/**/	ilk = gecici;
	}
	
	return ilk;
}

int bul(TOGRENCI *ilk, int dg)
{
	TOGRENCI *gecici;
	gecici = ilk;
	int i = 0, sira = 0;
	
	if (gecici==NULL)
	{
		sira=0;
	}
	else
	{

		while (gecici!=NULL)
		{
			i++;
			if (gecici->deger==dg)
			{
				sira=i;
				break;
			}

			gecici = gecici->sonraki;
		}
	}
	
	return sira;
}

TOGRENCI *sil(TOGRENCI *ilk, int dg)
{
	TOGRENCI *gecici=NULL, *ptr=NULL;
	
	if (ilk==NULL)
	{
		//return ilk;
	}
	else
	{
		gecici = ilk;
		
		while (gecici!=NULL)
		{
			if (gecici->deger==dg)
			{
				ptr = gecici;
				if (gecici->onceki!=NULL)
					gecici->onceki->sonraki = gecici->sonraki;
				if (gecici->sonraki!=NULL)
					gecici->sonraki->onceki = gecici->onceki;
				
				if (gecici==ilk)
					{
						if (gecici->sonraki!=NULL)
							ilk = gecici->sonraki;
						else
						    ilk = NULL;				
					}
				
				free(gecici);
				
				break;
			}
			else
   				gecici = gecici->sonraki;
		}
	}
	
	return ilk;
}

void listele(TOGRENCI *ilk)
{
	TOGRENCI *gecici;
	gecici = ilk;
	int i=0;

	if (gecici==NULL)
	{
		printf("Liste bos...\n");
	}
	else
	{
		while (gecici!=NULL)
		{
			printf("Liste %d  = %d \n", ++i, gecici->deger);
			gecici = gecici->sonraki;
		}
	}
}


void tumunuSil(TOGRENCI *ilk)
{
	TOGRENCI *gecici;
	gecici = ilk;
	
	while (ilk!=NULL)
	{  
		gecici = ilk;
		ilk    = ilk->sonraki;
		ilk->onceki = NULL;
		free(gecici);
	}	
}

int listeBoyutu(TOGRENCI *ilk)
{
	TOGRENCI *gecici;
	gecici = ilk;
	int i=0;
	
	while (gecici!=NULL)
	{  
		gecici = gecici->sonraki;
		i++;
	}	
	
	return i;
}


int main () 
{ 
	TOGRENCI *ilk=NULL, *gecici=NULL, *ptr=NULL;
	int devam=1;
	int sira =0;
	
	// [--LISTE OLUSTUR--]
	
	ilk=sonaEkle(ilk,5);
	ilk=sonaEkle(ilk,10);
	ilk=sonaEkle(ilk,7);
	ilk=basaEkle(ilk,8);
	ilk=basaEkle(ilk,9);
	ilk=basaEkle(ilk,6);

	listele(ilk);
	printf("\nToplam Kuyruk Uzunlugu %d\n\n",listeBoyutu(ilk));

	ilk=sil(ilk,10);
	ilk=sil(ilk,6);

	listele(ilk);
	printf("\nToplam Kuyruk Uzunlugu %d\n\n",listeBoyutu(ilk));

	sira=bul(ilk,8);
	if (sira>0)
	{
		printf("Aranan sayi %d indisinde bulunmustur\n",sira);
	}
	else
	{
		printf("Aranan sayi bulunamamistir\n");
	}

	tumunuSil(ilk);


	
	getch();
	
	return 0; 
	
}
