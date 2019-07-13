#include "stdio.h"
void arr(int array[], int i) {
  if (i<3) {
  scanf("%d",&array[i]);
  return arr(array,i+1);
  }

}
int rec(int array[],int i, int eb){
if (i<3) {
  if (array[i]>eb) {
    eb=array[i];
  }

    return rec(array,i+1,eb);
}
  if(i==3){
  return eb;
}
}
int main(int argc, char const *argv[]) {
  int array[10],i=0,j=0;
  arr(array,i);
  rec(array,i,j);
printf("%d\n",rec(array,i,j) );


  return 0;
}
/*#include "stdio.h"
void arr(int array[], int i) {
  if (i<3) {
  scanf("%d",&array[i]);
  return arr(array,i+1);
  }

}
int rec(int array[],int i,int eb){
  if (i==0) {
    eb=array[i];
    return rec(array,i+1,eb);
  }
  if (eb<array[i]) {
    eb=array[i];
    return rec(array,i+1,eb);
  }
  else
  printf("%d\n",eb );

}


int main(int argc, char const *argv[]) {
  int array[100],i=0,j;
  arr(array,i);
  rec(array,i,j);



  return 0;
}
*/
