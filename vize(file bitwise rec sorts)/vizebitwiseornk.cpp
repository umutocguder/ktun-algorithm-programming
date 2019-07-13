#include <stdio.h>
#include <conio.h>

int sifirla(int a, int start, int end)
{
      int k;
      for (k = start; k <= end; k++)
            a &= ~(1 << k);
      return a;
}

int birle (int a, int start, int end)
{
      int k;
      
      for (k = start; k <= end; k++)
            a |= 1 << k;
      return a;
}



int main()
{
      int s;
      int ilk=15 ; 
      int bit_deger1 = 1 ;
      int bit_deger2 = 2 ;
      printf( "ilk sayi: %d\n",ilk);
      
      s=sifirla(ilk,bit_deger1,bit_deger2); // 1111 -->1001
      printf(" %d. ve %d. bitleri sifirlandiginda deger : %d\n",bit_deger1,bit_deger2,s);
      s=birle(s,2,2);    // 1001 -->1111
      printf(" %d. ve %d. bitleri birlendiginde deger :%d\n",bit_deger1,bit_deger2,s);
         
		 s = 1 << bit_deger1;
		 	 printf(" %d. ve %d. bitleri birlendiginde deger :%d\n",bit_deger1,bit_deger2,s);
		 	 
      getch();
      return 0;
}


