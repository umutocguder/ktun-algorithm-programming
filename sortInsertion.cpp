#include <stdio.h>
#include <conio.h>
void insertion_sort(int arr[], int length);
int main() {
	int a[] = { 7, 12, 1, 8, 0, 15, 4, 11, 9, 6};
	int i;
	printf("\n\ilk dizi:  ");
	for(i = 0; i < 10; ++i) {
		printf(" %d ", a[i]);
	}
	insertion_sort(a, 10);
	printf("\n\nSon dizi:  ");
	for(i = 0; i < 10; ++i) {
		printf(" %d ", a[i]);
	}
}

void insertion_sort(int arr[], int length) {
	int i, j ,tmp;
	for (i = 6; i < length; i++) {
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
		}
	}
}
/*0
Insertion (Araya Ekleme) Sort:
Buyöntemdesıralanacakdizininikincielemanındanbaşlanarakmevcutelemanuygunkonumuna(arayaekleme)getirilereksıralamayapılmaktadır.
Buişlemmevcutelemanbiröncekikonumdabulunanelemandanküçükolduğuveilkkonumaulaşılmadığısürecedizielemanlarınınsağadoğru
kaydırılmasıilegerçekleşmektedir.Sıralamasırasındadiziikiparçahalindedüşünülebilir.Bunlarsıralıolanönkısımvehenüzsıralanmamı
şolanarkakısımdır.BestCasen,WorstCasen2çalışanbiralgoritmadır.O(n2),Ω(n),dolasıylaΘilesöylenemez.*/

/*void Selection(int dizi[],int n)
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
int Partition(int dizi[],int alt_indis,int ust_indis)
{ int i,j,pivot_degeri,pivot_indisi,gecici;
pivot_degeri=dizi[alt_indis]; //pivot en soldaki eleman
j=alt_indis;
for(i=alt_indis+1;i<=ust_indis;i++)
if (dizi[i]<pivot_degeri) //pivotun pozisyonu ayarlanıyor
{ j++;
gecici=dizi[i];dizi[i]=dizi[j];dizi[j]=gecici;
}
pivot_indisi=j; //pivotun olması gereken yeri j. hücredir.
gecici=dizi[alt_indis];
dizi[alt_indis]=dizi[pivot_indisi];
dizi[pivot_indisi]=gecici;
return pivot_indisi; //pivotun yeri döndürülür.
}
*/

/*1
#include <stdio.h>
#include <conio.h>

void insertionSort(int dizi[], int elemanSayisi)
{
     int temp;
     int i, j;

	 for (i = 1; i < elemanSayisi; i++)
	 {
 	 	 j = i;

		 while (j > 0 && dizi[j - 1] > dizi[j]) {
			 temp = dizi[j];
			 dizi[j] = dizi[j - 1];
			 dizi[j - 1] = temp;
			 j--;
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

	insertionSort( a, 9);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

    getch();

}

*/



/*2
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

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}



int main(int argc, char const *argv[]) {


  int arr[n],arr2[n],c,k,m,z,l;
  clock_t start, end;
  double cpu_time_used;


for (c = 0; c < n; c++) {
  arr[c] = rand() % 9999 + 1;
}

//Önce sırala
l = sizeof(arr)/sizeof(arr[0]);
insertionSort(arr,l);

//Terse çevir
reverseArray(arr,0,n);

Yazdır
for (c = 0; c < n; c++) {
   printf("%d\n",arr[c] );
 }


start = clock();
l = sizeof(arr)/sizeof(arr[0]);
insertionSort(arr,l);
end = clock();



printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );
printf("fdfdf\n" );
  return 0;
}

*/



























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

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}



int main(int argc, char const *argv[]) {


  int arr[n],arr2[n],c,k,m,z,l;
  clock_t start, end;
  double cpu_time_used;


for (c = 0; c < n; c++) {
  arr[c] = rand() % 9999 + 1;
}

//Önce sırala
l = sizeof(arr)/sizeof(arr[0]);
insertionSort(arr,l);

//Terse çevir
reverseArray(arr,0,n);

/*Yazdır
for (c = 0; c < n; c++) {
   printf("%d\n",arr[c] );
 }
*/

start = clock();
l = sizeof(arr)/sizeof(arr[0]);
insertionSort(arr,l);
end = clock();



printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );
printf("fdfdf\n" );
  return 0;
}

/*

Insertion Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.055
50000 = 1.379
100000 = 0.001

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0
50000 = 0
100000 = 0.001

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0.109
50000 = 2.704
100000 = 11.0

*/
