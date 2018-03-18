#include <stdio.h>

int size=0;
int arr [0];

int take(int number){
    *arr=(int)realloc(arr,(size+1)*sizeof(int));
    arr[size]=number;
    size++;
    int data=arr[size/2];
    return data;
}

int main(){
    printf("%d\n", take(20));
    printf("%d\n", take(10));
    printf("%d\n", take(30));
    printf("%d\n", take(5));
    printf("%d\n", take(40));
 return 0;
}
