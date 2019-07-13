//ders notları

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


struct dugum{
    char kelime[100];
    struct dugum *arka;
};


int main()
{
  FILE *fp;
  if ((fp=fopen("yeni.txt","r"))==NULL)
  {
     puts("Dosya Açılamadı...");
     getch();
     return 1;
  }
  dugum *ilk=(dugum*)malloc(sizeof(dugum));
  dugum *ptr=ilk;
  char temp[100];
  while (!feof(fp))
  {
   fscanf(fp,"%s",temp);
   strcpy(ptr->kelime,temp);
   ptr->arka=(dugum*)malloc(sizeof(dugum));
   ptr=ptr->arka;
  }
  ptr=ilk;
  printf("Dosyanin icerigi........");
  while (ptr!=NULL)
  {
   printf("%s\n",ptr->kelime);
   ptr=ptr->arka;
  }
getch();
}
 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct Liste{
int numara;
struct Liste *sonraki;
}BListe;

BListe *ilk=NULL,*son=NULL;



void Ekle(BListe *bilgi){
if(ilk==NULL)
    {
        ilk=bilgi;
        son=ilk;
        son->sonraki=NULL;
    }
    else
    {
        son->sonraki=bilgi;
        son=bilgi;
        son->sonraki=NULL;
    }
}

void Listele()
{
    BListe *gecici;
    gecici=ilk;
    if(gecici!=NULL)
        printf("%d\n",gecici->numara);
    else
        return;
    while(gecici->sonraki!=NULL)
    {
        gecici=gecici->sonraki;
        printf("%d\n",gecici->numara);
    }
}

void Silme(int num)
{
    BListe *gecici,*onceki;
    gecici=ilk;
    while(gecici)
    {
        if(gecici->numara==num)
            break;
        onceki=gecici;
        gecici=gecici->sonraki;
        if(gecici==ilk)
            break;
    }
    if(gecici!=NULL)
    {
        if(gecici==ilk)
        {
            if(gecici==son)
            {
                ilk=NULL;
                son=NULL;
            }
            else
            {
                ilk=ilk->sonraki;
            }
        }
        else
        {
            onceki->sonraki=gecici->sonraki;
            if(gecici==son)
               son=onceki;
        }
        printf("%d silindi.\n",gecici->numara);
        free(gecici);
    }
}



int main(){
BListe *Bilgi;
char secim;
while (1==1)
{
    puts("Ekleme : E\nListele : L\nSil : S\nCikis : C\n");
    secim=getch();
    switch(secim)
    {
        case 'e':
        {
            Bilgi =(BListe*)malloc(sizeof(BListe));
            printf("sayiyi gir ");
            scanf("%d",&Bilgi->numara);
            Ekle(Bilgi);
            break;
        }
        case 'l':
        {
            Listele();
            break;
        }
        case 'c':
        {
            return 0;
            break;
        }
        case 's':
        {
            printf("silinecek sayiyi gir.");
            int a;
            scanf("%d",&a);
            Silme(a);
            break;
        }
        default:
        {
            printf("Hatali Giris\n");
            break;
        }
    }
}
return 0;
}
