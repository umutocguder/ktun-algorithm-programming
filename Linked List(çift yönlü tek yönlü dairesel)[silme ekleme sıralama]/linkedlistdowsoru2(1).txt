//ekleme,silme,sýralama iþlemini yapan kod
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	struct node * next;
	int veri;
};
node *ilk,*son,*temp,*yeni,*gecici;
/*
void ekle(int x){
	yeni = (struct node*)malloc(sizeof(struct node*));
	yeni -> veri = x;
	yeni->next = NULL;
	if(ilk==NULL){
		ilk = yeni;
		son = ilk;
	}else{
		son->next=yeni;
		son=son->next;
	}
}
*/
void sil(int x){
	int kontrol = 0;
	if(ilk->veri==x){
		temp = ilk;
		ilk = ilk ->next;
		free(temp);
		kontrol = 1;
	}else{
		gecici = ilk;
		while(gecici->next!=NULL){
			if(gecici->next->veri == x){
				kontrol = 1;
				temp= gecici->next;
				if(temp == son){
					son = gecici;
					gecici->next=temp->next;
					free(temp);
					break;
				}
			}
			gecici = gecici -> next;
		}
	}
	if(kontrol==0){
		printf("yok");
	}
}
void yaz() {
    temp = ilk;
    while (temp != NULL) {
        printf("%d\n", temp->veri);
        temp = temp->next;
    }
}
void sirala(int x) {
 
    if (ilk == NULL) {
        ilk = (node*) malloc(sizeof (node));
        ilk->veri = x;
        ilk->next = NULL;
    } else {
        if ((ilk->veri) > x) {
            yeni = (node*) malloc(sizeof (node));
            yeni->veri = x;
            yeni->next= ilk;
            ilk = yeni;
        } else {
            gecici = ilk;
            yeni = (node*) malloc(sizeof (node));
            yeni->veri = x;
            while (gecici != NULL) {
                if (gecici->next == NULL && (gecici->veri) <= x) {
                    yeni->next = NULL;
                    gecici->next = yeni;
                    break;
                }
                if ((gecici->next->veri) > x) {
                    yeni->next = gecici->next;
                    gecici->next = yeni;
                    break;
                }
                gecici = gecici->next;
            }
        }
    }
}
 

int main(){

	
	sirala(25);
	sirala(11);
	sirala(36);
//	sil(11);
	yaz();
	
}
	
	
	
	
	
	

