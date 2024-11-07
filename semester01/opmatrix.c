#include <stdio.h>

int main(){
    int l, c, temp;

    scanf("%d%d", &l, &c);
    for(int i=0; i<l; i++){
        for(int ii=0; ii<c; ii++){
            scanf("%d", &temp);
            printf("%d ", -temp);
        }
        printf("\n");
    }
    return 0;
}