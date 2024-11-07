#include <stdio.h>

long function1(int);

int main(){
    long a;
    int b;

    scanf("%d", &b);

    a=function1(b);
    printf("%ld %d", a, b);
    return 0;
}

long function1(int b){
    static long a, r, fctor=1;

    
    if(b!=0){
        r = b % 2;
        a = a + r * fctor;
        fctor = fctor*10;
        printf("-- %ld %ld %ld\n", a, r, fctor);
        function1(b/2);
    }
    return a;
}