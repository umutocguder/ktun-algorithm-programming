#include "stdio.h"
void arrayal(int array[],int i){
  if (i<3) {
    scanf("%d",&array[i]);
    arrayal(array,i+1);
  }
}
void printarray(int array[],int i) {
  if (i<3) {
    printf("%d",array[i]);
    printarray(array,i+1);
  }

}

int main(int argc, char const *argv[]) {
  int i=0,array[10];
  arrayal(array,i);
  printarray(array,i);
  return 0;
}
