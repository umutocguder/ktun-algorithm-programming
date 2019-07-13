İŞARETÇİLER (Pointers)

Normal değişkeler tanımlandıkları türe göre bir değeri saklarlar.
 Bu değerlere değişkenin ismi ile ulaşılabilmektedir. İşaretçiler
 ise değerin saklandığı bellek adresini tutmaktadırlar. Değişkenin
 adresini kullanarak ta değere ulaşılabilmektedir. Uygulamalarda
 işaretçi kullanılması bazen kaçınılmazdır. Özellikle string
 işlemlerde ve dinamik bellek kullanımı gerektiren durumlarda.
Bir değişkenin önüne “*” işareti konulur ise bu onun bir işaretçi
olduğunu gösterir. Bildirimi;

tip *değişken_adı;

  işaretçinin kendisi de bir değişkendir ve tipi ne olursa olsun
   aynı uzunlukta yer kaplar.

#include <stdio.h>
#include <conio.h>

int main()
{
  int x=5;
  int *ptr=&x;

  printf("x=%d\n",x);               /*değişkenin değeri*/
  printf("ptr=%d\n",ptr);        /*değişkenin adresi*/
  printf("*ptr=%d\n",*ptr);   /*değişkenin değeri*/
  printf("&x=%d\n",&x);        /*değişkenin adresi*/

getch();
}

Bir işaretçinin önüne “*” konulur ise adres değerini değil
adreste saklı bulunan değeri verir.

#include <stdio.h>
#include <conio.h>
int main()
{
  int x;
  x=5;
  int *ptr;
  ptr=&x;

  printf("x'in adresi........:=%d\n",&x);
  printf("ptr'nin adresi.....:=%d\n",&ptr);
  printf("x'in değeri........:=%d\n",x);
  printf("ptr'nin değeri.....:=%d\n",ptr);

  printf("*ptr'in değeri.....:=%d\n",*ptr);
  printf("*&ptr'in değeri....:=%d\n",*&ptr);
  printf("&*ptr'in değeri....:=%d\n",&*ptr);

  *ptr=9;

  printf("*ptr'in değeri.....:=%d\n",*ptr);
  printf("x'in adresi........:=%d\n",&x);
  printf("x'in değeri........:=%d\n",x);

  getch();
}

#include <stdio.h>
#include <conio.h>
int main()
{
  int *ip1, *ip2, id1, id2;     /* 1 */

  ip1 = &id1;                        /* 2 */
  ip2 = &id2;                        /* 3 */
  id1 = 42;                            /* 4 */
  *ip2 = 67;  /* Dolaylı değer atama yöntemi */ /* 5 */

  printf("id1 değişkeninin değeri: %d\n", *ip1);
  printf("id2 değişkeninin değeri: %d\n", *ip2);
  printf("id1 değişkeninin bellek adresi: %p\n", ip1);
  printf("id2 değişkeninin bellek adresi: %p\n", ip2);
  getch();
}





İşaretçilerin gösterdiği bellek adresleri referans alınarak önceki
 veya sonraki adres alanlarına erişim ihtiyaçları olabilmektedir.
 Bu durumlarda işaretçiler üzerinde aritmetik işlemler
 kullanılabilmektedir. İşaretçilerde sadece toplama (+ , ++) ve
 çıkarma (-,--) operatörleri kullanılabilmektedir.

  int *a;
  float *b;
  char *c;

işaretçileri için a++,b++,c++ işlemleri kullanıldığında belirtilen
 adres değerleri tipin boyutuna göre değişmektedir. a++ 4 byte
 artarak, b++ 8 byte artarak, c++ 1 byte aratarak değişmektedir.
 Genel kural

tip *p;
p++  🡺 p=p+sizeof(tip);
p=p+n; 🡺 p=p+n*sizeof(tip);

Bir işaretçide bir dizinin başlangıç değeri var ve işaretçiye
4 eklemek dizinin 4. Elemanın adresini vermektedir.

#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{

  char str[100];
  puts("Bir Metin giriniz....:");
  gets(str);

  for (int i=0;i<strlen(str);i++)
       printf("%c\n",*(str+i));

  getch();
}









#include <stdio.h>
#include <conio.h>

main ()
{
  int *ip1;
  int idizi[5] = { 36, 64, 127, 152, 183 };

  ip1 = &idizi[0];

  printf("%d %d %p\n", idizi[0], *ip1, ip1);

  *ip1++;     /* 1 */ /* ip1++ ile aynı işlemi gerçekleştirir! */

  printf("%d %d %p\n", idizi[0], *ip1, ip1);

  (*ip1)++;   /* 2 */ /* idizi[1]++ ile aynı işlemi gerçekleştirir! */

  printf("%d %d %p\n", idizi[0], *ip1, ip1);
  getch();
}


Parametreleri işaretçi olarak tanımlama

#include <stdio.h>
#include <conio.h>
void change(int a,int b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
}

void ptr_change(int *a,int *b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
main ()
{
  int x=3,y=5;
  printf("x=%d y=%d\n",x,y);
  change(x,y);
  printf("x=%d y=%d\n",x,y);
  ptr_change(&x,&y);
  printf("x=%d y=%d\n",x,y);

  getch();
}
İşaretciler ile dizi işlemleri

#include <stdio.h>
#include <conio.h>

int my_strlen(char *s)
{
  char *t;
  t=s;
  while(*t != NULL)
     t++;
  return t-s;
}
int my_pos(char *s,char kr)
{
  char *t=s;
  int sayac=1;
  while(*t!=NULL)
    if (kr==*t) return sayac;
    else { t++; sayac++;}
  return -1;
}
main ()
{
  char str[100],krt;
  int l,p;
  puts("Metin Giriniz....:");gets(str);
  puts("Aranacak Karakteri Giriniz....:");scanf("%c",&krt);

  l=my_strlen(str);
  p=my_pos(str,krt);
  printf("Metnin Uzunluğu %d dir.\n %c k pozisyonu %d dir",l,krt,p);
  getch();
}


Dinamik diziler

malloc fonksiyonu istenilen byte kadar bellekten yer ayırır ve
başlangıç adresini geri gönderir. free komutu kullanılarak
 ayrılan alan serbest bırakılabilir.


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

main ()
{
  int *p,i,j,ek;
  srand(time(NULL));
  p=(int *) malloc(20*sizeof(int));
  for (i=0;i<20;i++)
  {
    *(p+i)=rand()%100;
    if (i==10) printf("\n");
    printf("%d - ",*(p+i));
  }
  ek=*p;
  for (i=1;i<20;i++)
  {
     if (*(p+i)<ek) ek=*(p+i);
  }
  printf("En kucuk eleman = %d",ek);
  free(p);
  getch();
}

Fonksiyonun bir işaretçi ile gösterilmesi

#include <stdio.h>
#include <conio.h>

int f(int n){
  int f=1, i;
  for(i=1; i<n; i++)
    f*=i;
  return f;
}

int main()
{
  int (*pf)(int);
  pf = &f;

  printf("Fonksiyonun adresi = %p\n", &f);
  printf("Fonksiyonun adresi = %p\n", pf);
  printf("Fonksiyonun adresi = %d\n", pf(5));
  getch();
  return 0;
}
















222222222222222222222.ders
İŞARETÇİLER

Örnek 1: Pointer Aritmetiği

#include <stdio.h>
#include <conio.h>
#include <stdio.h>

main()
{
int i[10], j;
int *iptr;

for (j=0; j<10; j++)
    i[j]=j;

iptr = i;
printf("\n (1) iptr'nin adresi.....:%p\n",iptr);
for (j=0; j<10; j++)
{
   printf("%d ", *iptr);
   iptr++;
}

printf("\n (2) iptr'nin adresi.....:%p\n",iptr);

/* iptr artık dizinin başını göstermez */

iptr = i;
printf("\n (3) iptr'nin adresi.....:%p\n",iptr);
for (j=0; j<10; j++)
    printf("%d ", *(iptr+j));

printf("\n (4) iptr'nin adresi.....:%p\n",iptr);;

/* iptr hala dizinin başını gösterir */

getch();
}


#include <stdio.h>
#include <conio.h>
#include <stdio.h>
void my_strcpy(char *destination, char *source)
{

    int i=0;
    while (*(source+i) != '\0')
    {
       *(destination+i) = *(source+i);
       i++;
    }
    *(destination+i) = '\0';
}

/*
char *my_strcpy(char *destination, char *source)
{
char *p = destination;
while (*source != '\0')
{
*p++ = *source++;
}
*p = '\0';
return destination;
}
*/
main()
{
  char strA[80],strB[80] = "12345678901234567890123456789012345678901234567890";
  my_strcpy(strA, strB);
  puts(strA);

  getch();
  return 0;
}
Örnek 2: void pointer

#include <stdio.h>
#include <conio.h>
#include <stdio.h>

int main()
{
  char    kar = 'a';
  int     tam = 66;
  double  ger = 1.2;
  void   *veri;

  veri = &kar;
  printf("veri -> kar: veri  %c  karakter degerini gosteriyor\n", *(char *) veri);

  veri = &tam;
  printf("veri -> tam: simdi veri  %d  tamsayi degerini gosteriyor\n", *(int *) veri);

  veri = &ger;
  printf("veri -> ger: simdi de veri  %lf  gercel sayi degerini gosteriyor\n", *(double *) veri);
  getch();
  return 0;
}


Örnek 3: pointerin pointeri

#include <stdio.h>
#include <conio.h>
#include <stdio.h>


main()
{
  int i;
  int *iptr;
  int **iptrptr;

  i = 5;
  iptr = &i;
  iptrptr = &iptr;


  printf("    i    ve    &i    :  %d   %p\n", i, &i);
  printf("  *iptr  ve   iptr   :  %d   %p\n", *iptr, iptr);
  printf("*iptrptr ve  iptrptr :  %p   %p\n", *iptrptr, iptrptr);

  getch();
  return 0;
}

Örnek 4: new ve delete komutları

#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <new.h>


int main ()
{
 int i,n;
 int *p;
 printf("Kac sayi gireceksiniz? ");
 scanf("%d",&i);
 p= new (nothrow) int[i];
 if (p == 0)
    printf("HATA!!! Hafıza tahsisi basarisiz oldu");
 else
 {
     for (n=0; n<i; n++)
     {
         printf("Sayilari giriniz: ");
         scanf("%d",(p+n));
     }

     printf("\n Girdiginiz sayilar: ");
     for (n=0; n<i; n++)
          printf("%d\n",*(p+n));
     delete[] p;
 }
 getch();
 return 0;
}

Örnek 5: Matris Örneği

#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main( void )
{
	int **matris;
	int satir_sayisi, sutun_sayisi;
	int i, j;

    srand (time(NULL));
	printf( "Satır sayısı giriniz> " );
	scanf( "%d", &satir_sayisi );
	printf( "Sütun sayısı giriniz> " );
	scanf( "%d", &sutun_sayisi );

	// Once satir sayisina gore hafizada yer ayiriyoruz.
	// Eger gerekli miktar yoksa, uyari veriliyor.
	matris = (int **)malloc( satir_sayisi * sizeof(int) );
	if( matris == NULL )
		printf( "Yetersiz bellek!" );

	// Daha sonra her satirda, sutun sayisi kadar hucrenin
	// ayrilmasini sagliyoruz.
	for( i = 0; i < satir_sayisi; i++ ) {
		matris[i] = (int *)malloc( sutun_sayisi * sizeof(int) );
		if( matris[i] == NULL )
			printf( "Yetersiz bellek!" );
	}

	for( i = 0; i < satir_sayisi; i++ ) {
		for( j = 0; j < sutun_sayisi; j++ )
			matris[i][j]=rand()%100;
	}

	// Ornek olmasi acisindan matris degerleri
	// gosteriliyor. Dizilerde yaptiginiz butun
	// islemleri burada da yapabilirsiniz.
	for( i = 0; i < satir_sayisi; i++ ) {
		for( j = 0; j < sutun_sayisi; j++ )
			printf( " %d ", matris[i][j] );
		printf( "\n" );
	}
/*		printf( "\n \n" );
	for( i = 0; i < satir_sayisi; i++ ) {
		for( j = 0; j < sutun_sayisi; j++ )
			printf( "%d ", (matris+(sutun_sayisi*i)+j) );
		printf( "\n" );
	}
*/
	// Bu noktada matris ile isimiz bittiginden
	// hafizayi bosaltmamiz gerekiyor. Oncelikle
	// satirlari bosaltiyoruz.
	for( i = 0; i < satir_sayisi; i++ ) {
		free( matris[i] );
	}
	// Satirlar bosaldiktan sonra, matrisin
	// bos oldugunu isaretliyoruz.
	free( matris );
    getch();
	return 0;
}

#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main( void )
{
	int *matris;
	int satir_sayisi, sutun_sayisi;
	int i, j;

    srand (time(NULL));
	printf( "Satır sayısı giriniz> " );
	scanf( "%d", &satir_sayisi );
	printf( "Sütun sayısı giriniz> " );
	scanf( "%d", &sutun_sayisi );

	// Once satir sayisina gore hafizada yer ayiriyoruz.
	// Eger gerekli miktar yoksa, uyari veriliyor.
	matris = (int *)malloc( satir_sayisi*sutun_sayisi* sizeof(int) );
	if( matris == NULL )
		printf( "Yetersiz bellek!" );

	// Daha sonra her satirda, sutun sayisi kadar hucrenin
	// ayrilmasini sagliyoruz.

	for( i = 0; i < satir_sayisi; i++ ) {
		for( j = 0; j < sutun_sayisi; j++ )
			*(matris+(sutun_sayisi*i)+j)=rand()%100;
	}

	// Ornek olmasi acisindan matris degerleri
	// gosteriliyor. Dizilerde yaptiginiz butun
	// islemleri burada da yapabilirsiniz.
	for( i = 0; i < satir_sayisi; i++ ) {
		for( j = 0; j < sutun_sayisi; j++ )
			printf( " %d ", matris[i*sutun_sayisi+j]);
		printf( "\n" );
	}
		printf( "\n \n" );
	for( i = 0; i < satir_sayisi; i++ ) {
		for( j = 0; j < sutun_sayisi; j++ )
			printf( "%d ", *(matris+(sutun_sayisi*i)+j) );
		printf( "\n" );
	}
	// Bu noktada matris ile isimiz bittiginden
	// hafizayi bosaltmamiz gerekiyor. Oncelikle
	// satirlari bosaltiyoruz.

	// Satirlar bosaldiktan sonra, matrisin
	// bos oldugunu isaretliyoruz.
	free( matris );
    getch();
	return 0;
}
Dinamik Dizi Örneği

#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main( void )
{
  int sayac=0,a;
  int *dizi=NULL;

  do
  {
    printf("Bir Sayı Giriniz...:");scanf("%d",&a);
    if (a<0) break;
    else
    {
      sayac++;
      dizi=(int *)realloc(dizi,sayac*sizeof(int));
      if (dizi!=NULL) {
       *(dizi+sayac-1)=a;
      }
      else
      {
       free (dizi);
       puts ("Error (re)allocating memory");
       getch();
       exit (1);
      }
    }
  }	while (1);
  for (int i=0;i<sayac;i++)
      printf(" %d ",*(dizi+i));
  getch();
}
Fonksiyonun bir işaretçi ile gösterilmesi

#include <stdio.h>
#include <conio.h>

int f(int n){
  int f=1, i;
  for(i=1; i<n; i++)
    f*=i;
  return f;
}

int main()
{
  int (*pf)(int);
  pf = &f;

  printf("Fonksiyonun adresi = %p\n", &f);
  printf("Fonksiyonun adresi = %p\n", pf);
  printf("Fonksiyonun adresi = %d\n", pf(5));
  getch();
  return 0;
}
