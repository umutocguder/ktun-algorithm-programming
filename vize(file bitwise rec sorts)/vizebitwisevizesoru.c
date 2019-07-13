/*Klavyeden girilen herhangi bir tamsayıyı aşağıdaki örnekte belirtildiği gibi işleme tabi tutarak ekrana ikili sayı sistemi
 karşılığını yazdıran bir program yazınız. (Her bir bayta aynı işlem uygulanmıştır.)
Örnek: Girilen sayı: 351055694  İkili karşılığı 00010100 11101100 10101111 01001110
            Sonuç ekran görüntüsü böyle olacak  00011111 11101111 10101111 01001111
            //15le |lamış her bytı*/
// çözüldü.....
            #include "stdio.h"
            void Goster(unsigned sayi)
            {	int i, Maske=1<<31;
            	printf("%u :",sayi);
            	for(i=1;i<33;i++)
            	{
            		putchar(sayi&Maske? '1' : '0');
            		sayi<<=1;
            		if(i%8==0) putchar(' ');
            	}
            	printf("\n");
            }

int main(int argc, char const *argv[]) {
int a,mask=15,i;
  printf("int gir");
  scanf("%d",&a);
  Goster(a);
  for (i = 0; i <3; i++) {
    mask<<=8;
    mask+=15;
  }
  Goster(a|mask);
  return 0;
}
