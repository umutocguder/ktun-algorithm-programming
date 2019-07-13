#include <stdio.h>
#include <conio.h>
void change(int a,int b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;  
}

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
  change(x,y);
  printf("x=%d y=%d\n",x,y);
  ptr_change(&x,&y);
  printf("x=%d y=%d\n",x,y);
  
  getch();
}
