#include <stdio.h>

int main(){
    int l, c, temp, biggest, first=1;

    scanf("%d%d", &l, &c);
    for(int i=0; i<l; i++){
        for(int ii=0; ii<c; ii++){
            scanf("%d", &temp);
            if(first){
                biggest = temp;
                first = 0;
            }
            if(temp>biggest) biggest=temp;
        }
    }
    printf("%d", biggest);
    return 0;
}