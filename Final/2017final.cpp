#include<stdio.h>
#include<stdlib.h>
//KLAVYEDEN KULLANICI İSTEDİĞĞİ SÜRECE GİRİLEN İNT VERİ TİPİNDEKİ TAM SAYILARI TEK YÖNLÜ BİR BAĞLI LİSTEYE SIRALI OLARAK EKLEYEN(YERLEŞTİREN PROGRAM)
/*struct kayit {                                                           //   1. S O R U
	int data;
	kayit *sonraki;
};

kayit *ilk=NULL,*gecici=NULL,*son=NULL,*prev=NULL;

void tersYazdir(kayit*);

int main()
{
	int devam;

	do{

		if(ilk==NULL){

			ilk=(kayit*)malloc(sizeof(kayit));
			printf("Deger Giriniz\t:");scanf("%d",&ilk->data);
			ilk->sonraki=NULL;
			son=ilk;
			}
		else{

			gecici=(kayit*)malloc(sizeof(kayit));
			printf("Deger giriniz\t:");scanf("%d",&gecici->data);

			if(gecici->data>ilk->data){

				gecici->sonraki=ilk;
				ilk=gecici;
				gecici=NULL;
				}
			else if(gecici->data<son->data){

				gecici->sonraki=NULL;
				son->sonraki=gecici;
				son=gecici;
				gecici=NULL;
				}
			else{

				prev=ilk;
				while(gecici->data<prev->sonraki->data)prev=prev->sonraki;
				gecici->sonraki=prev->sonraki;
				prev->sonraki=gecici;
				gecici=NULL;
				prev=NULL;
				}
			}
			printf("Devam etmek icin (1)");scanf("%d",&devam);
		}while(devam==1);

		gecici=ilk;

		while(gecici!=NULL){
			printf("%d  ",gecici->data);
			gecici=gecici->sonraki;
		}
}*/



//PARAMETRE OLARAK İLK ELEMANI VERİLEN VE SORALI OLDUĞU KABUL EDİLEN TEK YÖNLÜ BİR BAĞLI LİSTEYİ RESTEM EKRANA YADIRAN REC FONKSİYONU

/*void tersYazdir(kayit *ilk){                                               //   2. S O R U

	if(ilk->sonraki==NULL)printf("%d  ",ilk->data);

	else{

		tersYazdir(ilk->sonraki);
		printf("%d  ",ilk->data);
	}

}*/




// SIRALI OLARAK ERİŞİLEBİLİNEN FİNAL.TXT İSİMLİ DOSYADA her
bir satırda bir adet olmak ğzre alt alta int veri tipinde sayilar
bulunmaktarie sadece bir döngü kullanarak belirtilen dosyadaki tek
sayilari tek yönlü bağlı listeye aynı anda çift sayilari farklı
 bir tej yönlü bağlı listeye aktaran aktarım sonrasında ise bağlı
 iste içeriklerini ekrana yazdıran program

/*struct kayit {                                                           //   3. S O R U
	int data;
	kayit *sonraki;
};

int main(){

	kayit *ilktek=NULL,*ilkcift=NULL,*gecici=NULL,*prev=NULL;

	FILE *dosya=fopen("final.txt","r");

	int sayi;

	while(!feof(dosya)){

		fscanf(dosya,"%d",&sayi);

		if(sayi%2==1&&ilktek==NULL){

			ilktek=(kayit*)malloc(sizeof(kayit));
			ilktek->data=sayi;
			ilktek->sonraki=NULL;
		}
		else if(sayi%2==1&&ilktek!=NULL){

			prev=ilktek;
			gecici=(kayit*)malloc(sizeof(kayit));
			gecici->data=sayi;
			while(prev->sonraki!=NULL)prev=prev->sonraki;
			prev->sonraki=gecici;
			gecici->sonraki=NULL;
		}
		else if(sayi%2==0&&ilkcift==NULL){

			ilkcift=(kayit*)malloc(sizeof(kayit));
			ilkcift->data=sayi;
			ilkcift->sonraki=NULL;
		}
		else{

			prev=ilkcift;
			gecici=(kayit*)malloc(sizeof(kayit));
			gecici->data=sayi;
			while(prev->sonraki!=NULL)prev=prev->sonraki;
			prev->sonraki=gecici;
			gecici->sonraki=NULL;
		}
	}
	fclose(dosya);

	gecici=ilktek;

	while(gecici!=NULL){

		printf("%d  ",gecici->data);
		gecici=gecici->sonraki;
	}

	printf("\n");

	gecici=ilkcift;

	while(gecici!=NULL){

		printf("%d  ",gecici->data);
		gecici=gecici->sonraki;
	}
}*/
//3. soru alternatif
/*
typedef struct n
{
    int x;
    struct n* next;
}node;


node* Ekle(node* kok , int x )
{
    if(kok == NULL)
    {
        kok = (node*)malloc(sizeof(node));
        kok -> x = x;
        kok -> next = NULL;
        return kok;
    }
    else
    {
        node * ilerle = kok;
        while(ilerle -> next != NULL)
        {
            ilerle = ilerle -> next;
        }
        node * temp = (node*)malloc(sizeof(node));
        temp -> x = x;
        temp -> next = NULL;
        ilerle -> next = temp;
        return kok;

    }
}

void bastir(node* kok)
{
    while(kok != NULL)
    {
        printf(" %d -",kok -> x);
        kok = kok -> next;
    }
    printf("\n");
}
int main()
{
    node * tek = NULL;
    node * cift = NULL;
    int x;

    while(x != -1)
    {
        printf("Bir Say˝ Giriniz veya i˛lemi bitirmek iÁin '-1' giriniz : ");
        scanf("%d",&x);
        if(x == -1)
        {
            break;
        }
        else
        {
            if(x % 2 == 0)
            {
                cift = Ekle(cift,x);
            }
            else
            {
                tek = Ekle(tek,x);
            }

        }
    }
    bastir(tek);
    bastir(cift);
}

*/






//100 elemanlı ibt veri tipinde tamsataikardan olyşan bir
diziyi klavyeden okuduktan sonra diziyi selection algoritması
ile sıralayan daha sonra diziyi ve sıralama işlemi yapılırjeb kaç
defa  yer değişim işlemi yapıldığını ekrana yadıran program




//4. soru
/*
void selectionSort (int dizi[], int elemanSayisi);


int main()
{
    int a[] = { 7, 12, 1, 8, 0, 15, 4, 11, 9};

    int i;
    printf("\n\nUnsorted array is:  ");
    for(i = 0; i < 9; ++i)
        printf(" %d ", a[i]);

    selectionSort( a, 9);

    printf("\n\nSorted array is:  ");
    for(i = 0; i < 9; ++i)
        printf(" %d ", a[i]);

    getch();

}

void selectionSort (int dizi[], int elemanSayisi)
{
    int i, j, enKucuk, temp,a=0;
    for (i=0; i<elemanSayisi-1; i++)
    {
        enKucuk = i;
        for (j=i+1; j<elemanSayisi; j++)
        {
            if (dizi[j] < dizi [enKucuk])
                enKucuk = j;
        }
        if(dizi[i]!=dizi[enk¸Á¸k])
        {
            a++;
            temp = dizi[i];
            dizi[i] = dizi[enKucuk];
            dizi[enKucuk] = temp;
        }

    } for(i=0;i<=100,i++)
    {
        printf("%d")
    }
}
*/
//Klavyeden kullanıcı istediği sürece int ceri tipindeki sayilari girilen sayi tej ise tek yönlü bağlı listenin başına çift ise aynı tek yönlü bağlı listenin sonuna ekleyen program..


/*struct kayit {                                                           //   5. S O R U
	int data;
	kayit *sonraki;
};

int main(){

	kayit *ilk=NULL,*gecici=NULL,*son=NULL;

	int sayi,devam;

	do{
		printf("Deger giriniz\t:");scanf("%d",&sayi);

		if(ilk==NULL){

			ilk=(kayit*)malloc(sizeof(kayit));
			ilk->data=sayi;
			son=ilk;
			son->sonraki=NULL;
		}
		else if(sayi%2==1){

			gecici=(kayit*)malloc(sizeof(kayit));
			gecici->data=sayi;
			gecici->sonraki=ilk;
			ilk=gecici;
		}
		else{
			gecici=(kayit*)malloc(sizeof(kayit));
			gecici->data=sayi;
			son->sonraki=gecici;
			son=gecici;
			son->sonraki=NULL;
		}
		printf("Devam etmek icin (1)");scanf("%d",&devam);
	}while(devam==1);

	gecici=ilk;

	while(gecici!=NULL){
		printf("%d  ",gecici->data);
		gecici=gecici->sonraki;
	}
}*/
//5 alternatif
/*
typedef struct n
{
    int x;
    struct n* next;
}node;


node* Ekle(node* kok , int x )
{
    if(kok == NULL)
    {
        kok = (node*)malloc(sizeof(node));
        kok -> x = x;
        kok -> next = NULL;
        return kok;
    }
    else
    {


        if( x%2 == 1)//Say˝ Tekse
        {
            node * temp = (node*)malloc(sizeof(node));
            temp -> x = x;
            temp -> next = kok;
            return temp;
        }
        else //Say˝ Áiftse
        {
            node * ilerle = kok;
            while(ilerle->next != NULL)
            {
                ilerle = ilerle -> next;
            }

            node* temp = (node*)malloc(sizeof(node));
            temp -> x = x;
            temp -> next = NULL;
            ilerle -> next = temp;
            return kok;
        }

    }
}

void bastir(node* kok)
{
    while(kok != NULL)
    {
        printf(" %d -",kok -> x);
        kok = kok -> next;
    }
}
int main()
{
    node * kok = NULL;
    int x;

    while(x != -1)
    {
        printf("Bir Say˝ Giriniz veya i˛lemi bitirmek iÁin '-1' giriniz : ");
        scanf("%d",&x);
        if(x == -1)
        {
            break;
        }
        else
        {
            kok = Ekle(kok,x);
        }
    }
    bastir(kok);
}
*/
