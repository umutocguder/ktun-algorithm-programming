#include <stdio.h>
#include <conio.h>

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
	dosya = fopen("bilgisayarBNR.dat","r");    
    
    // eger dosya acilmissa dosya isaretcisi NULL / 0 'dan farkli olur
	if (!dosya) return -1;
        
    int i=0;
    
    // Binary veri oku -> fread(struct_degiskeni_adresi, okunacak_boyut, okunacak_adet, dosya_isaretcisi);
	fread(&ogr,sizeof(ogr),1, dosya);
    
    // dosya sonuna gelinip gelinmedigini kontrol et -> feof(dosya_isaretcisi)
	while (!feof(dosya)){
       printf("Ad:%s Soyad:%s V:%d F:%d ",ogr.ad,ogr.soyad,ogr.vize,ogr.final);

	   // dosyadaki konumu ver
	   printf("konum : %d   \n",ftell(dosya));	   

	   fread(&ogr,sizeof(ogr),1, dosya);   
	   i++;
    }
 
    
    // dosyayi kapat -> fclose(dosya_isaretcisi)
	fclose(dosya);
    
    getch();
 
 
	//fseek(dosya,1*sizeof(ogr),SEEK_SET); // SEEK_CUR , SEEK_END
	//rewind();
	//fflush(stdin);
	//rename("eski.txt", "yeni.txt");
	//remove("deneme.txt");

    
    return 0;
}
