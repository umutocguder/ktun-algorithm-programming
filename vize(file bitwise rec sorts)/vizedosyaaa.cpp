/* ogrenci.txt dosyasý içindeki öðrenci notlarýný deðiþtirme */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    FILE *dg;           /* dosya göstericisi */
    char  Ad[10];
    int   No, Not, sayac, ogrno, ogrnot, kontrol;

    dg = fopen("ogrenci.txt", "r+");

    if(  dg == NULL )
      printf("ogrenci.txt dosyasi acilmadi. !\n"), exit(1);

    kontrol = 0;
    do {
        printf("Ogrenci numarasi giriniz : ");
        scanf("%d",&ogrno);
        sayac = 0; // bulunduðu satýr numarasý (ilk satir 0)
        while( !feof(dg) ) {
               fscanf(dg,"%d %s %d",&No,Ad,&Not);
               if(No == ogrno) {
                     kontrol = 1; // ogrenci bulundu
                     break;
               }
               sayac++;
        }
        if(kontrol == 0)
               printf("%d numarali ogrenci bulunamadi! \n", ogrno);
        else
               printf("Ogrenci adi : %s, notu : %d \n\n", Ad, Not);
    } while(kontrol == 0);
    
    printf("Yeni notu giriniz : ");
    scanf("%d",&ogrnot);
    
    rewind(dg); // imleci dosya baþýna alma
    
    fseek(dg, sayac * 22 + 17, SEEK_SET); // 5(no) + 1(boþluk) + 10(ad) + 1(boþluk) + 3(not) + 2(altsatir ve satýrbaþý) = 22
    
    fprintf(dg, "%3d", ogrnot); 

    /* dosyayý kapat */
    fclose(dg);  

    puts("Bilgiler kaydedildi.\a");
    
    getch();

    return 0;
}
