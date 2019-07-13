#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct TREE {
	int value;
	char chr;
	struct TREE *left;  // -> 0
    struct TREE *right; // -> 1
};

void InOrder(TREE *r);
void Leaf(TREE *r);
void printCodes(TREE* root, int arr[], int top);

int main()
{

	TREE *root=NULL, *ptr, *temp;
	
	int values[] = {10,20,25,40,60};
	int chrs[] = {'E','D','C','B','A'};

	root = (TREE*) malloc(1*sizeof(TREE));	
	root->value  = values[0];
	root->chr    = chrs[0];;
	root->left   = NULL;
	root->right  = NULL;

	
	for (int i=1;i<5;i++)
	{

		ptr = (TREE*) malloc(1*sizeof(TREE));	
		ptr->value  = values[i];
		ptr->chr    = chrs[i];
		ptr->left   = NULL;
		ptr->right  = NULL;

		temp = (TREE*) malloc(1*sizeof(TREE));	
		temp->left   = ptr;
		temp->right  = root;

		temp->value  = temp->left->value + temp->right->value;
		temp->chr    = '*';

		root = temp;
		
	}

	printf("\n\n Agac Olusturuldu \n\n"); 
	
	printf("In order : "); 
	InOrder(root);
	printf("\n\n"); 
	printf("\n\n"); 
	
	
	int arr[4], top = 0;
	
	printCodes(root, arr, top);
	printf("\n\n"); 
	printf("\n\n"); 
	
	
	getch();
	
}

void InOrder(TREE *r)
{
	if (r->left!=NULL) InOrder(r->left);
	printf("%c[%d] ",r->chr, r->value);
	if (r->right!=NULL) InOrder(r->right);
}

void printCodes(TREE* r, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (r->left)
    {
        arr[top] = 0;
        printCodes(r->left, arr, top + 1);
    }
 
    // Assign 1 to right edge and recur
    if (r->right)
    {
        arr[top] = 1;
        printCodes(r->right, arr, top + 1);
    }
 
    // If this is a leaf node, then it contains one of the input
    // characters, print the character and its code from arr[]
	if ((r->left==NULL) && (r->right==NULL))
    {
        printf("%c: ", r->chr);

	    int i;
	    for (i = 0; i < top; ++i)
	        printf("%d", arr[i]);
	    printf("\n");
    }
}
