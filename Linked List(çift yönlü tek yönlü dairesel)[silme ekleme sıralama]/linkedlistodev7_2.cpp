//2. ödev
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	struct node * next;
	int veri;
};
node *first,*last,*temp,*nw,*temp;
void add(int x){
	nw = (struct node*)malloc(sizeof(struct node*));
	nw -> veri = x;
	nw->next = NULL;
	if(first==NULL){
		first = nw;
		last = first;
	}else{
		last->next=nw;
		last=last->next;
	}
}
void delete(int x){
	int count = 0;
	if(first->veri==x){
		temp = first;
		first = first ->next;
		free(temp);
		count = 1;
	}else{
		temp = first;
		while(temp->next!=NULL){
			if(temp->next->veri == x){
				count = 1;
				temp= temp->next;
				if(temp == last){
					last = temp;
					temp->next=temp->next;
					free(temp);
					break;
				}
			}
			temp = temp -> next;
		}
	}
	if(count==0){
		printf("yok");
	}
}
void wr() {
    temp = first;
    while (temp != NULL) {
        printf("%d\n", temp->veri);
        temp = temp->next;
    }
}
void sort(int x) {
 
    if (first == NULL) {
        first = (node*) malloc(sizeof (node));
        first->veri = x;
        first->next = NULL;
    } else {
        if ((first->veri) > x) {
            nw = (node*) malloc(sizeof (node));
            nw->veri = x;
            nw->next= first;
            first = nw;
        } else {
            temp = first;
            nw = (node*) malloc(sizeof (node));
            nw->veri = x;
            while (temp != NULL) {
                if (temp->next == NULL && (temp->veri) <= x) {
                    nw->next = NULL;
                    temp->next = nw;
                    break;
                }
                if ((temp->next->veri) > x) {
                    nw->next = temp->next;
                    temp->next = nw;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
 

int main(){

	
	sort(21);
	sort(11);
	sort(13);
	delete(11);
	wr();
	
}
