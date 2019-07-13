#include <stdio.h>
#include <malloc.h>

//Düğümleri tutacağımız struct yapımız
struct node {

    int data;
    struct node *next;
    struct node *prev;
};

//Başlangıç düğümü bizim için çok önemli, global değişken olarak tanımladık ve başlangıçta NULL atadık.
struct node* start = NULL;

//Düğüm olusturup return eden fonksiyon
struct node* dugumOlustur(int veri)
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data = veri;
    yeniDugum->next = NULL;
    yeniDugum->prev = NULL;

    return yeniDugum;
}

//Çift yönlü bağlı listede sona düğüm ekleyen fonksiyon
void sonaEkle(int veri)
{
    struct node* sonaEklenecek = dugumOlustur(veri);

    //Eğer listede hiç eleman yoksa yeni eleman ekliyoruz
    if (start == NULL)
    {
        start = sonaEklenecek;
    }

    else
    {
        //traverse etmek için temp değişkenine start değişkenini atadık, maksat start değişkenini bozmamak.
        struct node* temp = start;

        //Aşağıdaki döngü traverse yapıyor ve temp düğümü döngü sonunda son düğüm oluyor.
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        //temp elemanı (eski son) olduğu için sonaEklenecek (yeni son) düğümünün prev işaretçisi tempi gösterecek.
        sonaEklenecek->prev = temp;

        //temp değişkeninin next işaretçisi ise artık yeni son elemanımız olan sonaEklenecek düğümünü işaret edecek.
        temp->next = sonaEklenecek;
    }
}

//Çift yönlü bağlı listede başa düğüm ekleyen fonksiyon
void basaEkle(int veri)
{
    struct node* basaEklenecek = dugumOlustur(veri);

    if (start == NULL)
    {
        start = basaEklenecek;
        return;
    }

    start->prev = basaEklenecek;
    basaEklenecek->next = start;
    start = basaEklenecek;
}

//Çift yönlü bağlı listede araya düğüm ekleyen fonksiyon
void arayaEkle(int kiminOnune, int eklenecek)
{
    struct node* temp = start;
    struct node* arayaEklenecek = dugumOlustur(eklenecek);
    struct node* onceki = NULL;

    if (start == NULL)
    {
        start = arayaEklenecek;
    }
    else if(start->data == kiminOnune)
    {
        basaEkle(eklenecek);
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == kiminOnune)
            {
                onceki = temp->prev;
                break;
            }
            temp = temp->next;
        }
        temp->prev = arayaEklenecek;
        arayaEklenecek->next = temp;
        arayaEklenecek->prev = onceki;
        onceki->next = arayaEklenecek;
    }


}

//Çift yönlü bağlı listede baştan düğüm silen fonksiyon
void bastanSil()
{
    if (start == NULL)
    {
        printf("\n Liste zaten bos ....");
        return;
    }

    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }

    struct node* ikinci = start->next;
    free(start);
    ikinci->prev = NULL;
    start = ikinci;
}

//Çift yönlü bağlı listede sondan düğüm silen fonksiyon
void sondanSil()
{
    if (start == NULL)
    {
        printf("\n Liste zaten bos ....");
        return;
    }

    if (start->next == NULL)
    {
        bastanSil();
        return;
    }

    struct node* temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = NULL;
}

//Çift yönlü bağlı listede aradan düğüm silen fonksiyon
void aradanSil(int silinecek)
{
    struct node* temp = start;
    while (temp->next != NULL)
    {
        if (temp->data == silinecek)
            break;
        temp = temp->next;
    }
    struct node* sonraki = temp->next;
    struct node* onceki = temp->prev;
    free(temp);
    onceki->next = sonraki;
    sonraki->prev = onceki;
}

//Düğüm yapısını ekrana
void yazdir()
{
    struct node* temp = start;

    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}



int main()
{

    int i, secim, sayi, sayi1;

    while (1)
    {
        printf("\n 1- sona eleman ekleme");
        printf("\n 2- basa eleman ekleme");
        printf("\n 3- araya eleman ekleme");
        printf("\n 4- bastan eleman sil");
        printf("\n 5- sondan eleman sil");
        printf("\n 6- aradan eleman sil");
        printf("\n Seciminizi yapin ... ");
        scanf_s("%d", &secim);

        switch (secim)
        {
            case 1:
                printf("\n Sona Eklemek istediginiz elemani girin ... ");
                scanf_s("%d", &sayi);
                sonaEkle(sayi);
                yazdir();
                break;
            case 2:
                printf("\n Basa Eklemek istediginiz elemani girin ... ");
                scanf_s("%d", &sayi);
                basaEkle(sayi);
                yazdir();
                break;

            case 3:
                printf("\n Araya Eklemek istediginiz sayiyi girin ... ");
                scanf_s("%d", &sayi);
                printf("\n Hangi elemanin onune eklemek istiyorsunuz... ");
                scanf_s("%d", &sayi1);
                arayaEkle(sayi1, sayi);
                yazdir();
                break;
            case 4:
                bastanSil();
                yazdir();
                break;

            case 5:
                sondanSil();
                yazdir();
                break;

            case 6:
                printf("\n Silinmesini istedigini elemani girin ... ");
                scanf_s("%d", &sayi);
                aradanSil(sayi);
                yazdir();
                break;

        }
    }

    return 0;
}
//////////////////
//sıralı erişimli olarak oluşturulduğu kabul edilen bir.txt isimli dosya i.öerisinde int veri
//tipinden tamsayilar bulunmaktadır. busayilarin tamamını olyirıracağımız bir çift yönlü bağlı
//listeye sıralı olarak aktaran program kodnu yazınız

#include<stdio.h>
#include<stdlib.h>

struct DEGER{
    int veri;
    struct DEGER *next;
    struct DEGER *prev;
};
struct DEGER *temp , *ilk , *gecici ,*son;
void ekle(){

    FILE *fp = fopen("bir.txt","r+");
    int deger;
    while(!feof(fp)){
        fscanf(fp,"%d",&deger);
        if(ilk == NULL){
            ilk = (struct DEGER*)malloc(sizeof(struct DEGER*));
            ilk -> veri = deger;
            ilk -> next = NULL;
            ilk -> prev = NULL;
        }else{
            if(ilk->veri > deger){
                temp = (struct DEGER*)malloc(sizeof(struct DEGER*));
                temp -> veri = deger;
                temp->next = ilk;
                temp -> prev = NULL;
                ilk = temp;
                son = ilk;
            }
            else{
                if(son->veri < deger){
                    temp = (struct DEGER*)malloc(sizeof(struct DEGER*));
                    temp -> veri = deger;
                    son -> next = temp;
                    temp -> prev = son;
                    temp->next=NULL;
                    son = temp;
                }else{
                    temp = ilk;
                    while(temp!=NULL){
                        if(temp->next->veri > deger){

                            gecici = (struct DEGER*)malloc(sizeof(struct DEGER*));
                            gecici->veri = deger;
                            gecici->next =temp->next;
                            temp->next= gecici;
                            gecici->prev = temp;
                            gecici->next->prev = gecici;
                            break;
                        }
                        temp = temp->next;
                    }
                }
            }
        }
    }
}


void yaz(){
    temp = ilk;
    while (temp!= NULL) {
        printf("%d\n",temp->veri);
        temp = temp->next;
    }
}
int main(){

    ekle();
    yaz();
    return 0;
}

Dairesel tek yönlü bir bağlı liste yapısında ekleme, silme
ve sıralama işlemlerini yapan program kodunu yazınız.


Sıralı erişimli olarak oluşturulduğu kabul edilen bir.txt isimli
dosya içerisinde integer veri tipinden tamsayılar bulunmaktadır.
Bu sayıların tamamını oluşturacağınız bir çift yönlü bağlı listeye
sıralı olarak aktaran program kodunu yazınız.
