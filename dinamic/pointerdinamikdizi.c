#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int com = 0,a,i;
    int *array = NULL;
    while (1) {
        printf("sayi giriniz\n");
        scanf("%d",&a);

        if (a<0) {
            break;
        }

        else{
            if (a%5 == 0  && a%3 == 0) {
                com++;
                array = realloc(array,com*sizeof(int));
                *(array+com-1) = a;
            }
        }
    }
    for(i=0;i<com;i++){
        printf("%d\n",*(array+i));
    }
    return 0;
}
