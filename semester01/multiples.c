#include <stdio.h>

int main(){
    int m2=0, m3=0, m5=0, ma=0, max, i=1;

    scanf("%d", &max);
    while(i<=max){
        if(i%2==0 && i%3==0 && i%5==0) ma++;
        if(i%2==0) m2++;
        if(i%3==0) m3++;
        if(i%5==0) m5++;
        i++;
    }

    printf("Múltiplos de 2: %d\nMúltiplos de 3: %d\nMúltiplos de 5: %d\nMúltiplos de todos: %d", m2, m3, m5, ma);

    return 0;
}