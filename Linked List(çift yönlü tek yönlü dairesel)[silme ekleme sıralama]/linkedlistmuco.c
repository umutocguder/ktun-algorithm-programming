
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
