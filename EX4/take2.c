#include <stdio.h>
#include <stdlib.h>

int size=1;
int arr [1];

int comper (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int take2(int number){
    *arr=(int)realloc(arr,(size+1)*sizeof(int));
    arr[size]=number;
    size++;
    qsort(arr, size, sizeof(int), comper);
    return arr[size/2];
}

int main(){
    printf("%d\n", take2(20));
    printf("%d\n", take2(10));
    printf("%d\n", take2(30));
    printf("%d\n", take2(5));
    printf("%d\n", take2(40));
 return 0;
}
