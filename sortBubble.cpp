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

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1]){
             swap(&arr[j], &arr[j+1]);
           }

}


int main(int argc, char const *argv[]) {


  int arr[n],arr2[n],c,k,m,z;
  clock_t start, end;
  double cpu_time_used;


for (c = 0; c < n; c++) {
  arr[c] = rand() % 9999 + 1;
}

//Önce sırala
//bubbleSort(arr,n);
//Terse çevir
//reverseArray(arr,0,n);

/*Yazdır
for (c = 0; c < n; c++) {
   printf("%d\n",arr[c] );
 }
*/

start = clock();
bubbleSort(arr,n);
end = clock();



printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );

  return 0;
}

/*

Bubble Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.257
50000 = 7.291
100000 = 28.918

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0.1
50000 = 2.359
100000 = 9.469

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0.238
50000 = 5.726
100000 = 23.033

*/




















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

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1]){
             swap(&arr[j], &arr[j+1]);
           }

}


int main(int argc, char const *argv[]) {


  int arr[n],arr2[n],c,k,m,z;
  clock_t start, end;
  double cpu_time_used;


for (c = 0; c < n; c++) {
  arr[c] = rand() % 9999 + 1;
}

//Önce sırala
//bubbleSort(arr,n);
//Terse çevir
//reverseArray(arr,0,n);

/*Yazdır
for (c = 0; c < n; c++) {
   printf("%d\n",arr[c] );
 }
*/

start = clock();
bubbleSort(arr,n);
end = clock();



printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );

  return 0;
}

/*

Bubble Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.257
50000 = 7.291
100000 = 28.918

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0.1
50000 = 2.359
100000 = 9.469

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0.238
50000 = 5.726
100000 = 23.033

*/





























#include <stdio.h>
#include <conio.h>


void bubbleSort(int dizi[], int elemanSayisi)
{
     int temp;
     int i, j;

     for (i=0; i<elemanSayisi-1; i++)
     {
         for (j=0; j<elemanSayisi; j++)
         {
             if(dizi[j] > dizi[j+1])
             {
                  temp = dizi [j];
                  dizi [j] = dizi [j+1];
                  dizi [j+1] = temp;
             }
         }
     }
}

int main()
{
	int a[] = { 7, 12, 1, 8, 0, 15, 4, 11, 9};

	int i;
	printf("\n\nUnsorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

	bubbleSort(a, 9);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

    getch();

}































#include <stdio.h>
#include <conio.h>

void bubbleSort(int dizi[], int elemanSayisi);


int main()
{
	int a[] = { 7, 12, 1, 8, 0, 15, 4, 11, 9};

	int i;
	printf("\n\nUnsorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

	bubbleSort( a, 8);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

    getch();

}

void bubbleSort(int dizi[], int elemanSayisi)
{
     int temp;
     int i, j;

     for (i=0; i<elemanSayisi; i++)
     {
         for (j=1; j<elemanSayisi; j++)
         {
             if(dizi[j] > dizi[j+1])
             {
                        temp = dizi [j];
                        dizi [j] = dizi [j+1];
                        dizi [j+1] = temp;
             }
         }
     }
}
