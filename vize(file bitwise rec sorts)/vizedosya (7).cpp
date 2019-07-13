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
    
	// Dosya isaretcisi 
	FILE *dosya;

	// Dosya ac -> fopen(dosya_adi, mod)
	dosya = fopen("bilgisayarBNR.dat","a+");    
    
    // eger dosya acilmissa dosya isaretcisi NULL / 0 'dan farkli olur
	if (!dosya) return -1;
        
    int i;
    
    // Binary veri yaz -> fwrite(struct_degiskeni_adresi, okunacak_boyut, okunacak_adet, dosya_isaretcisi);

	strcpy(ogr.ad,"d_ad");
	strcpy(ogr.soyad,"d_soyad");
	ogr.vize=70;
	ogr.final=90;
	ogr.ortalama=ogr.vize*0.4+ogr.final*0.6;
    fwrite(&ogr,sizeof(ogr),1, dosya);
	
	strcpy(ogr.ad,"bilgi");
	strcpy(ogr.soyad,"sayar");
	ogr.vize=20;
	ogr.final=40;
	ogr.ortalama=ogr.vize*0.4+ogr.final*0.6;
    fwrite(&ogr,sizeof(ogr),1, dosya);
	
	strcpy(ogr.ad,"selcuk");
	strcpy(ogr.soyad,"kampus");
	ogr.vize=60;
	ogr.final=70;
	ogr.ortalama=ogr.vize*0.4+ogr.final*0.6;
    fwrite(&ogr,sizeof(ogr),1, dosya);

 
    
    // dosyayi kapat -> fclose(dosya_isaretcisi)
	fclose(dosya);
    
    getch();
    
    return 0;
}
