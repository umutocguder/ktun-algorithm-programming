#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main (){
	srand(time(NULL));
	int array[100];
	int j=0,temp1,temp2;
	int *pa;
	pa=(int *)malloc((100*sizeof(int)));
	for(int i=0;i<100;i++){
		array[i]=rand()%100;
	}
	for (int i=0;i<100;i++){
		temp1=array[i];
		temp1=temp1<<27;
		temp2=temp1>>31;
		if((temp2&1)==0){
			*(pa+j)=array[i];
			j++;
		}
	}
	while((*pa)!=NULL){
		printf("%d \n",*(pa));
		pa++;
	}
	return 0;
}
