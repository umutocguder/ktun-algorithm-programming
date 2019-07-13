#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void pselection(int * array,int n){
	int i,j,min, temp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(array[j]>array[min]){
				min=j;
			}
		}
		temp=*(array+min);  
		*(array+min)=*(array+i);
		*(array+i)=temp;
	}
}
int main (){
	int array[20];
	int *ptr;
	srand(time(NULL)); 
	for(int i=0;i<20;i++){
		array[i]=rand()%100;
	}
	ptr=array; 
	pselection(ptr,20);
	for(int i=0;i<20;i++){
		printf("%d  ",*(ptr+i));
	}
	return 0;
}
