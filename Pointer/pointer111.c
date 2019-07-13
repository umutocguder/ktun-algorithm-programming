/*
#include <stdio.h>
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
    ptr_change(&x,&y);
    printf("x=%d y=%d\n",x,y);
//}*/
/*

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 int main(int argc, char const *argv[]) {

 int *ptr;
 int x,i,sayi;
 int j = 0;
 ptr = (int *)malloc((100*sizeof(int)));
 int dizi[j];
 do{
 printf("sayi gir:");
 scanf("%d",&x);
 j++;
 dizi[j] = x;

 }while(x>0);
 for(i=1;i<j;i++){
 ptr=dizi;
 }
 for(i=1;i<j;i++){
 if((*(dizi+i)%3==0)&&(*(dizi+i)%5==0)){
 printf("%d ",*(dizi+i));
 }
 }
 return 0;
 }
 */
 /*
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 void selectionSort (int * dizi, int elemanSayisi)
 {
 int i, j, less, temp;
 for (i=0; i<elemanSayisi-1; i++)
    {
    less = i;
    for (j=i+1; j<elemanSayisi; j++)
        {
        if (dizi[j] < dizi [less])
        less = j;
        }
    temp = *(dizi+i);
    *(dizi+i) =*(dizi+less);
    *(dizi+less) = temp;
    }
 }
 int main(int argc, char const *argv[]) {
 int *ptr;
 int x,i;
 int j = 0;
 ptr = (int *)malloc((j*sizeof(int)));
 int dizi[j];
 do{
 printf("sayi gir:");
 scanf("%d",&x);
 j++;
 dizi[j] = x;
 }while(x>0);
 for(i=1;i<j;i++){
 ptr=dizi;
 }
 for(i=1;i<j;i++){
 selectionSort(ptr,j);
 }
 for(i=1;i<j;i++){
 printf("%d ",*(ptr+i));
 }
 return 0;
 }
*/
   #include <stdio.h>
   #include <stdlib.h>
   #include <time.h>

   void sel (int *array, int size)
   {
   int i, j, min, temp;
   for (i=0; i<size-1; i++)
   {
   min = i;
   for (j=i+1; j<size; j++)
   {
   if (*(array+j) < *(array+min))
   min = j;
   }
   temp = *(array+i);
   *(array+i) = *(array+min);
   *(array+min) = temp;
   }
   }

   int main() {

   int com = 0,a,i;
   int *array = NULL;

   while (1) {
   printf("sayi giriniz....\n");
   scanf("%d",&a);
   if (a<0) {
   break;
   }else{
   com++;
   array = realloc(array,com*sizeof(int));
   *(array+com-1) = a;
   }
   }
   printf("array\n");
   for(i=0;i<com;i++){
   printf("%d\n",*(array+i));
   }

   // SIRALAMA
   sel(array,com);
   printf("Sirali array\n");
   for(i=0;i<com;i++){

   printf("%d\n",*(array+i));
   }

   return 0;
   }
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int com = 0,a,i;
    int *array = NULL;
    while (1) {
        printf("sayi giriniz\n");
        scanf("%d",&a);

        if (a<0) {
            break;
        }

        else{
            if (a%5 == 0  && a%3 == 0) {
                com++;
                array = realloc(array,com*sizeof(int));
                *(array+com-1) = a;
            }
        }
    }
    for(i=0;i<com;i++){
        printf("%d\n",*(array+i));
    }
    return 0;
}
