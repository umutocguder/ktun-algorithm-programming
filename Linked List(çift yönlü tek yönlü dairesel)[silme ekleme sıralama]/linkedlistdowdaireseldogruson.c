#include"stdio.h"
#include"conio.h"
typedef struct Liste{
int numara;
struct Liste *next;
}BListe;
BListe *ilk=NULL,*son=NULL;

void Ekle(BListe *veri){
if(ilk==NULL)
    {
        ilk=veri;
        son=ilk;
        ilk->next=ilk;
    }
    else
    {
        son->next=veri;
        son=veri;
        son->next=ilk;
    }
}
void Listele()
{
    BListe *gecici;
    gecici=ilk;
    while(gecici->next!=ilk)
    {
        printf("%d\n",gecici->numara);
        gecici=gecici->next;
    }
    printf("%d\n",gecici->numara);
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
        gecici=gecici->next;
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
                ilk=ilk->next;
                son->next=ilk;
            }
        }
        else
        {
            onceki->next=gecici->next;
            if(gecici==son)
               son=onceki;
        }
        printf("%d silindi.\n",gecici->numara);
        free(gecici);
    }
}



int main(){
BListe *veri;
char secim;
while (1==1)
{
    puts("Ekleme\nListele\nSil\nCikis\n");
    secim=getch();
    switch(secim)
    {
        case 'e':
        {
            veri =(BListe*)malloc(sizeof(BListe));
            printf("sayiyi gir ");
            scanf("%d",&veri->numara);
            Ekle(veri);
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
       
    }
}
return 0;
}
