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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
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
mergeSort(arr,0,l-1);

//Terse çevir
reverseArray(arr,0,n);

/*Yazdır
for (c = 0; c < n; c++) {
   printf("%d\n",arr[c] );
 }
*/

start = clock();
l = sizeof(arr)/sizeof(arr[0]);
mergeSort(arr,0,l-1);
end = clock();



printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );

  return 0;
}

/*

Merge Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.002
50000 = 0.008
100000 = 0.015

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0.001
50000 = 0.003
100000 = 0.008

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0
50000 = 0.005
  100000 = 0.009

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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
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
mergeSort(arr,0,l-1);

//Terse çevir
reverseArray(arr,0,n);

/*Yazdır
for (c = 0; c < n; c++) {
   printf("%d\n",arr[c] );
 }
*/

start = clock();
l = sizeof(arr)/sizeof(arr[0]);
mergeSort(arr,0,l-1);
end = clock();



printf("%f\n",cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC );

  return 0;
}

/*

Merge Sort

a)  Rasgele Sayılar (Random Numbers)
10000 = 0.002
50000 = 0.008
100000 = 0.015

# b)  Sıralı Olan Sayılar (Ordered Numbers)
10000 = 0.001
50000 = 0.003
100000 = 0.008

# c)  Tersten Sıralı (Ordered Reverse Numbers)
10000 = 0
50000 = 0.005
  100000 = 0.009

*/






















/*Merge Sort
Busıralamayöntemindebölveyönetyaklaşımınadayanır.Sıralanmasıistenendizielemanlarıönce2altdiziyeayrılır.Altkümelereayırmaişleminealtkümelerdekibirtaneelemankalanakadardevamedilir.Altkümelerde1taneelemankalmışsarekürsifçağırmageriyedoğrudönmeyebaşlarvegeridönülürkenaltkümelerelemanlarısıralıolacakşekildebirleştirilir.EveryCaseRunningTimebiralgoritmadır.Herdurumdanlognzamandaçalışmaktadır.O(nlogn),Ω(nlogn),dolasıylaΘ(nlogn)
Birleştirmelisıralama,çalışmazamanınıiyileştirmekiçinşuikifikirüzerinekuruludur:
1.Küçükbirlisteyisıralamak,büyükbirlisteyisıralamaktandahaazadımdayapılabilir.
2.Sıralıikialtlistedenbirsıralılisteeldeetmek,sırasızikialtlistedenbirsıralılisteeldeetmektendahaazadımdayapılabilir.*/
void Mergesort(int Dizi [], int ilk, int son)
{ if (ilk < son)
{ int orta = (ilk + son) / 2;
Mergesort(Dizi, ilk, orta); // dizi bölünüyor
Mergesort(Dizi, orta + 1, son); // dizi bölünüyor
Merge(Dizi, ilk, orta, son); // birleştiriliyor
}
}
void Merge(int Dizi[], int ilk, int orta, int son)
{ int tempArray[1000]; // geçici dizi tanımlanıyor
int ilk1 = ilk; int son1 = orta; // birinci altdizinin başlangıcı ve sonu
int ilk2 = orta + 1; int son2 = son; // ikinci altdizinin başlangıcı ve sonu
int index = ilk1; // geçici dizinin indisi ayarlanıyor
for ( ; (ilk1 <= son1) && (ilk2 <= son2); index++) //Geçici diziye elemanlar sıralı alınıyor
{if (Dizi[ilk1] < Dizi[ilk2]) { tempArray[index] = Dizi[ilk1];
ilk1++; }
else {tempArray[index] = Dizi[ilk2];
ilk2++; }
}
for (; ilk1 <= son1; ilk1++, index++) // birinci altdizinin elemanları bitmemişse
tempArray[index] = Dizi[ilk1];
for (; ilk2 <= son2; ilk2++, index++) // ikinci altdizinin elemanları bitmemişse
tempArray[index] = Dizi[ilk2];
for (index = ilk; index <= son; index++) //gecici dizi orjinal diziye kopyalanır(merge)
Dizi[index] = tempArray[index];
}
