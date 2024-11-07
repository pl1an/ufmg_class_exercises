#include <stdio.h>

int main(){
    int arr[11];

    for(int i=0; i<10; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<10; i++){
        printf("%d\n", arr[9-i]);
    }
    
    return 0;
}