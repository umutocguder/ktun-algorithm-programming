#include "stdio.h"
#include <stdlib.h>
#include "time.h"


int n = 100000;

void reverseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}


int main(int argc, char const *argv[]) {


  int arr[n],arr2[n],c,k,m,z;
  clock_t start, end;
  double cpu_time_used;


for (c = 0; c < n; c++) {
  arr[c] = rand() % 9999 + 1;
}

// Önce sırala
selectionSort(arr,n);
//Terse çevir
reverseArray(arr,0,n);

/* Yazdır
for (c = 0; c < n; c++) {
  printf("%d\n",arr[c] );
}
*/

start = clock();
selectionSort(arr,n);
end = clock();

printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );

  return 0;
}

/*

Selection Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.110000
50000 = 2.546
100000 = 10.529

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0.104
50000 = 2.531
100000 = 10.406

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0.145
50000 = 3.809
100000 = 11.827

*/





























/*
den
#include "stdio.h"
#include <stdlib.h>
#include "time.h"


int n = 100000;

void reverseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}


int main(int argc, char const *argv[]) {


  int arr[n],arr2[n],c,k,m,z;
  clock_t start, end;
  double cpu_time_used;


for (c = 0; c < n; c++) {
  arr[c] = rand() % 9999 + 1;
}

// Önce sırala
selectionSort(arr,n);
//Terse çevir
reverseArray(arr,0,n);

/* Yazdır
for (c = 0; c < n; c++) {
  printf("%d\n",arr[c] );
}
*/

start = clock();
selectionSort(arr,n);
end = clock();

printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );

  return 0;
}

/*

Selection Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.110000
50000 = 2.546
100000 = 10.529

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0.104
50000 = 2.531
100000 = 10.406

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0.145
50000 = 3.809
100000 = 11.827

*/













/*#include <stdio.h>
#include <conio.h>

void selectionSort (int dizi[], int elemanSayisi)
{
     int temp;
     int enKucukIndis;
     int i, j;

     for (i=0; i<elemanSayisi-1; i++)
     {
         enKucukIndis = i;
         for (j=i+1; j<elemanSayisi; j++)
         {
             if (dizi[j] < dizi [enKucukIndis])
             enKucukIndis = j;
         }

		 temp = dizi[i];
         dizi[i] = dizi[enKucukIndis];
         dizi[enKucukIndis] = temp;
     }
}


int main()
{
	int a[] = { 7, 12, 1, 8, 0, 15, 4, 11, 9};

	int i;
	printf("\n\nUnsorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

	selectionSort( a, 9);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

    getch();

}
*/




















/*#include <stdio.h>
#include <conio.h>

void selectionSort (int dizi[], int elemanSayisi);


int main()
{
	int a[] = { 7, 12, 1, 8, 0, 15, 4, 11, 9};

	int i;
	printf("\n\nUnsorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

	selectionSort( a, 9);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

    getch();

}

void selectionSort (int dizi[], int elemanSayisi)
{
     int i, j, enKucuk, temp;
     for (i=0; i<elemanSayisi-1; i++)
     {
         enKucuk = i;
         for (j=i+1; j<elemanSayisi; j++)
         {
             if (dizi[j] < dizi [enKucuk])
             enKucuk = j;
         }
         temp = dizi[i];
         dizi[i] = dizi[enKucuk];
         dizi[enKucuk] = temp;
     }
}
*/
























/*Selection Sort
Bualgoritmadadizininilkelemanındanbaşlanarak,ilkelemandizidekienküçükelemanile,ikincielemandizidekiikincienküçükeleman
ileyerdeğiştirilmektedir.Buişlemsonelemanakadartekrarlanarakdizisıralanmışolmaktadır.EveryCaseRunningTimebiralgoritmadır.
Herdurumdan2zamandaçalışmaktadır.O(n2),Ω(n2),dolasıylaΘ(n2)
*/
void Selection(int dizi[],int n)
{ int i,j,min,gecici;
for (i=0;i<n-1;i++)
{ min=i; //i. eleman küçük kabul ediliyor
for (j=i+1;j<n;j++) //ileride daha küçük var mi taranıyor
if (dizi[j]<dizi[min]) min=j;
gecici=dizi[min]; // dizi[i] ve dizi[min] takas yapılıyor
dizi[min]=dizi[i];
dizi[i]=gecici;
}
}























ödev
#include "stdio.h"
#include "time.h"

void Insertion(int array[], int n){
   int i,k,j;
   for (;n<100;n++){
       k = array[n];
       j = n;
       while (j > 0 && k<array[j-1]){
           array[j] = array[j-1];
           j--;
       }
       array[j] = k;
   }
}

void Selectionters(int array[], int n){
  int i,j,min,temp;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(array[j]>array[min]){
        min=j;
      }
    }
    temp=array[min];
    array[min]=array[i];
    array[i]=temp;
  }
}

int main(int argc, char const *argv[]) {

  int array[100],i,j;

  srand(time(NULL));
  for(i=0;i<100;i++){
    array[i] = rand()% 100;
  }



  Selection(array,50);
  printf("\nilk 50 selection sort ile tersten sirali\n\n");
  for(i=0;i<50;i++){
    printf("%d\n",array[i]);
  }

  Insertion(array,50);
  printf("\n\nson 50 insertion sort ile duzden sirali\n\n" );
  for(i=50;i<100;i++){
    printf("%d\n",array[i]);
  }


  return 0;
}
