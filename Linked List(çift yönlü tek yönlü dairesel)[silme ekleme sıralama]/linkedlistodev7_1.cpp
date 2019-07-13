
//sıralı erişimli olarak oluşturulduğu kabul edilen bir.txt isimli dosya i.öerisinde int veri
//tipinden tamsayilar bulunmaktadır. busayilarin tamamını olyirıracağımız bir çift yönlü bağlı
//listeye sıralı olarak aktaran program kodnu wrınız

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

 struct VALUE{
	int veri;
	struct VALUE *next;
	struct VALUE *prev;
};
struct VALUE *temp , *first , *temp ,*last;
void add(){
	
	FILE *fp = fopen("bir.txt","r+");
	int VALUE;
	while(!feof(fp)){
		fscanf(fp,"%d",&VALUE);
		if(first == NULL){
			first = (struct VALUE*)malloc(sizeof(struct VALUE*));
			first -> veri = VALUE;
			first -> next = NULL;
			first -> prev = NULL;
		}
        else{
			if(first->veri > VALUE){
				temp = (struct VALUE*)malloc(sizeof(struct VALUE*));
				temp -> veri = VALUE;
				temp->next = first;
				temp -> prev = NULL;
				first = temp;
				last = first;
        }
        else{
				if(last->veri < VALUE){
					temp = (struct VALUE*)malloc(sizeof(struct VALUE*));
					temp -> veri = VALUE;
					last -> next = temp;
					temp -> prev = last;
					temp->next=NULL;
					last = temp;
        }
        else{
					temp = first;
					while(temp!=NULL){
						if(temp->next->veri > VALUE){
						
						temp = (struct VALUE*)malloc(sizeof(struct VALUE*));
						temp->veri = VALUE;
              			temp->next =temp->next;
              			temp->next= temp;
              			temp->prev = temp;
              			temp->next->prev = temp;
              			break;
            }
					temp = temp->next;
				}
			}
				}
			}
		}
	}
	

void wr(){
	temp = first;
  	while (temp!= NULL) {
    printf("%d\n",temp->veri);
    temp = temp->next;
  }
}
int main(){
add();
wr();
	return 0;
}
