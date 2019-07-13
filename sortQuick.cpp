#include "stdio.h"
#include <stdlib.h>
#include "time.h"


int n = 100;

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

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}



void quickSort(int arr[], int low, int high) {
    if (low < high)
    {
        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
quickSort(arr,0,l-1);

//Terse çevir
////reverseArray(arr,0,n);

/*Yazdır
for (c = 0; c < n; c++) {
   printf("%d\n",arr[c] );
 }
*/



start = clock();
l = sizeof(arr)/sizeof(arr[0]);
quickSort(arr,0,l-1);
end = clock();



printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );

  return 0;
}

/*

Quick Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.001
50000 = 0.007
100000 = 0.013

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0.253
50000 = 37.000 üstü çalışmıyor  3.547
100000 =

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0.112
50000 = 1.6
100000 =

*/



























#include <stdio.h>
#include <conio.h>

void quickSort( int[], int, int);
int partition( int[], int, int);


int main()
{
	int a[] = { 7, 12, 1, 8, 0, 15, 4, 11, 9};

	int i;
	printf("\n\nUnsorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

	quickSort( a, 0, 8);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < 9; ++i)
		printf(" %d ", a[i]);

    getch();

}

//	int a[] = { 7, 12, 1, 8, 0, 15, 4, 11, 9};
void quickSort( int a[], int l, int r)
{
   int j;
   if( l < r )
   {
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
}
int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}





























den
#include "stdio.h"
#include <stdlib.h>
#include "time.h"


int n = 100;

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

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}



void quickSort(int arr[], int low, int high) {
    if (low < high)
    {
        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
quickSort(arr,0,l-1);

//Terse çevir
////reverseArray(arr,0,n);

/*Yazdır
for (c = 0; c < n; c++) {
   printf("%d\n",arr[c] );
 }
*/



start = clock();
l = sizeof(arr)/sizeof(arr[0]);
quickSort(arr,0,l-1);
end = clock();



printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );

  return 0;
}

/*

Quick Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.001
50000 = 0.007
100000 = 0.013

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0.253
50000 = 37.000 üstü çalışmıyor  3.547
100000 =

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0.112
50000 = 1.6
100000 =

*/






























/*Quick Sort
Bualgoritmadabölveyönet(divideandconquer)politikasınadayanır,sıralanmasıistenendizibelirlibirsınır(pivot)değerinegöreikialtdiziyeayrılır.İkiyeayırmaişlemipivottanküçükelemanlarpivotunsoluna,pivottanbüyükelemanlarpivotunsağınayerleşecekşekildeyerdeğiştirmeişlemikullanılaraksağlanır.Dahasonrapivotunsağıvesoluolmaküzereeldeedilmişolan2diziiçindeyinebirpivotdeğeribelirlenerekbuişlemdizilerparçalanmayacakdurumagelenekadarsürdürülür.BestCasenlogn,WorstCasen2çalışanbiralgoritmadır.O(n2),Ω(nlogn),dolasıylaΘilesöylenemez.
Böl& YönetStratejisi
1.Problemi küçük parçalara böl
2.Her bir parçayı bağımsız şekilde çöz
3.Parçaları birleştirerek ana problemin çözümüne ulaş
*/
void Quicksort(int dizi[],int alt,int ust)
{ int pivot_indisi;
if (ust>alt)
{ pivot_indisi=Partition(dizi,alt,ust);
Quicksort(dizi,alt,pivot_indisi-1);//pivottan küçükler
Quicksort(dizi,pivot_indisi+1,ust);//pivottan büyükler
}
}




























ödev
#include "stdio.h"
#include "time.h"

int partition(int array[], int p, int r){
    int pv = array[r],tmp;
    while (p < r){
		while (array[p] < pv){
            p++;
        }
        while (array[r] > pv){
            r--;
        }
        if (array[p] == array[r]){
            p++;
        }
        else if (p < r){
            tmp = array[p];
            array[p] = array[r];
            array[r] = tmp;
        }
    }
    return r;
}

//copy paste sadece 2. 3. while işaretleri değiş
int partition1(int array[], int p, int r){
    int pv = array[r],tmp;
    while (p < r){
		while (array[p] > pv){
            p++;
        }
        while (array[r] < pv){
            r--;
        }
        if (array[p] == array[r]){
            p++;
        }
        else if (p < r){
            tmp = array[p];
            array[p] = array[r];
            array[r] = tmp;
        }
    }
    return r;
}

void quick(int * input, int p, int r){
  int j;
	if (p < r){
        j = partition(input, p, r);
        quick(input, p, j - 1);
        quick(input, j + 1, r);
    }
}

//copy paste sadece fonks değiş
void quick1(int * input, int p, int r){
  int j;
	if (p < r){
        j = partition1(input, p, r);
        quick1(input, p, j - 1);
        quick1(input, j + 1, r);
    }
}

int main (int argc, char const *argv[]){

	int array[100],i,j;

  srand(time(NULL));
	for(i=0;i<100;i++){
		array[i]=rand()% 100;
	}

  //ilk duz sirali
	quick(array,0,50);
	printf("ilk 50 sirali\n\n");
	for(i=0;i<50;i++){
		printf("%d \n",array[i]);
	}

  //ikinci ters sirali
	quick1(array,50,100);
	printf("\nson 50 ters sirali\n\n");
	for(i=50;i<100;i++){
		printf("%d\n",array[i]);
	}

	return 0;
}
