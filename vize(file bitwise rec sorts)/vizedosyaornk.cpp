/* Ogrenci.txt dosyasyndan no, isim ve not bilgileri okur ve
   notlar arasyndan en b�y�?�, en k���?� ve synyf ortlamasyny
   (0'lar hari�) hesaplar. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *dg;        /* dosya i?aret�isi */
   char  Ad[10];
   int   Not, No, eb, ek, n, top;
   float ort;

   if( (dg=fopen("ogrenci.txt","r")) == NULL )
     puts("Dosya a�ylmady !\n"), exit(1);

   /* ba?langy� de?erleri ata */
   ek  =  1000;  /* �ok b�y�k */
   eb  = -1000;  /* �ok k���k */
   top = 0;      /* notlaryn toplamy */
   n   = 0;      /* notu 0'dan farly �?rencilerin toplamy */

   while( !feof(dg) )                    /* dosyanyn sonuna kadar */
   {
      fscanf(dg,"%d %s %d",&No,Ad,&Not); /* verileri oku! */

      if(Not>eb) eb = Not;               /* en b�y�k ve en k���k bulunuyor... */
      if(Not<ek) ek = Not;

      if(Not) n++;                       /* Not 0'dan farkly my? */

      top += Not;                        /* Notlarin toplamy */
   }

   fclose(dg);                           /* dosyayy kapat */

   ort = (float) top/n;                  /* ortalama (0 lar hari�!) */

   printf("En yuksek not = %2d\n",eb);   /* sonu�lar ekrana ... */
   printf("En  dusuk not = %2d\n",ek);
   printf("Ortalama      = %4.1f\n",ort);

 return 0;
}
