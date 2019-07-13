#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct dugum{
        int bilgi;
        struct dugum *on;
        struct dugum *arka;
        } node;

node *ilk=NULL, *son=NULL;

int ekleme(node *a)
{
   if (ilk==NULL) //ilk node
   {
    ilk = a;
    son = a;
    ilk->arka = ilk;
    ilk->on = ilk;
   }
   else // node varsa
   {
    son->arka = a;
    a->on = son;
    son = a;
    son->arka = ilk;
    ilk->on=son;    
   }
   return 0;
}

int listeleme()
{
    node *gecici;
    gecici = ilk;
    if (gecici == NULL) return -1; // listede node yok
    do 
    {
     printf("%d\n",gecici->bilgi);
     gecici = gecici->arka;
    } while (gecici != ilk);
    return 0;
}

node *arama ( int a)
{
     node *gecici;
     gecici = ilk;
     do 
     {
      if (a == gecici->bilgi) 
         return gecici;
      gecici = gecici->arka;
     }while (gecici != ilk);
     return NULL;
}

int silme( int a)
{
    node *gecici;
    gecici = arama(a);
    if (gecici == NULL) return -1; // silinecek node yok
    
    if (ilk == gecici) // ilk node mu silinecek
    {
       if (ilk->arka != ilk) // listede birden fazla node var mý?
       {
        ilk = gecici->arka;
        ilk->on = son;
        son->arka=ilk;
       }
       else
       {
        ilk = NULL;
        son = NULL;
       }
    }
    else
    {
        gecici->on->arka = gecici->arka;
        if (gecici  == son ) // silinen son node mu?
        {  
           son = son->on;
           son->arka = ilk;
           ilk->on = son;
        }
        else
           gecici->arka->on = gecici->on;    
            
    }
    free(gecici);
    return 0;
}

int kaydet()
{
    FILE *fp;
    node *gecici;
    
    if ((fp = fopen("bliste.txt","w")) == NULL)
    {
       puts("Dosya Açma Hatasý...");
       return -1;
    }
    
    gecici = ilk;
    printf("\n");
    do 
    {
          fprintf(fp,"%d\n",gecici->bilgi);
          gecici = gecici->arka;
    }while (gecici != ilk);
    printf("Kaydetme iþlemi Tamamlandý\n");
    fclose(fp);
    return 0;
}

int yukle ()
{
    FILE *fp;
    node *gecici;
    int temp;
    if ((fp = fopen("bliste.txt","r")) == NULL)
    {
       puts("Dosya Açma Hatasý...");
       return -1;
    }
    printf("\n");
    while (!feof(fp))
    {
          gecici = (node *) malloc(sizeof(node));
          if (gecici == NULL) 
          {
            puts("Bellekte yer alma iþlemi hatasý...");
            break;
          }
          fscanf(fp,"%d",&temp);
          gecici->bilgi = temp;
          ekleme(gecici); 
    }
    printf("Yukleme iþlemi Tamamlandý\n");
    fclose(fp);

}


int main(){
node *d;
char secim;
while (1==1)
{
    puts("Ekleme : 1\nListele : 2\nSil : 3\nKaydet : 4\nYukle : 5\nCikis : 6\n");
    secim=getch();
    switch(secim)
    {
        case '1':
        {
            d =(node *)malloc(sizeof(node));
            printf("Sayi gir...:");
            scanf("%d",&d->bilgi);
            ekleme(d);
            break;
        }
        case '2':
        {
            listeleme();
            break;
        }
        case '3':
        {
            printf("silinecek sayiyi gir.");
            int a;
            scanf("%d",&a);
            silme(a);
            break;
        }        
        case '4':
        {
            kaydet();
            break;
        }
        case '5':
        {
            yukle();
            break;
        }
        case '6':
        {
            return 0;
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

























