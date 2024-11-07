#include <stdio.h>

int main(){
    int count=233;
    do{
        printf("%d\n", count);
        if(count<400 && count>300)count+=3;
        else count+=5;
    }while(count<=457);
    return 0;
}