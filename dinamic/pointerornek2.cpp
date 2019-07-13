#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

main ()
{
  int *p,i,j,ek;
  srand(time(NULL));
  p=(int *) malloc(20*sizeof(int));
  for (i=0;i<20;i++)
  {
    *(p+i)=rand()%100;
    if (i==10) printf("\n");
    printf("%d - ",*(p+i));
  } 
  ek=*p;
  for (i=1;i<20;i++)
  {
     if (*(p+i)<ek) ek=*(p+i);
  }
  printf("En kucuk eleman = %d",ek);
  free(p);
  getch();
}

