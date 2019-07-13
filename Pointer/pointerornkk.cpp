#include <stdio.h>
#include <conio.h>

int my_strlen(char *s)
{
  char *t;
  t=s;
  while(*t != NULL)
     t++;
  return t-s;
}
int my_pos(char *s,char kr)
{
  char *t=s;
  int sayac=1;
  while(*t!=NULL)
    if (kr==*t) return sayac;
    else { t++; sayac++;}
  return -1;
}
main ()
{
  char str[100],krt;
  int l,p;
  puts("Metin Giriniz....:");gets(str);
  puts("Aranacak Karakteri Giriniz....:");scanf("%c",&krt);

  l=my_strlen(str);
  p=my_pos(str,krt);
  printf("Metnin Uzunluðu %d dir.\n %c karakterinin pozisyonu %d dir",l,krt,p);
  getch();
}

