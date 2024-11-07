#include <stdio.h>
#include <stdlib.h>

int is_prime(int prime){
    for(int i=2; i<=prime/2; i++){
        if(prime%i==0) return 0;
    }
    return 1;
}

void primos(int m, int *p1, int *p2){
    int t=1, ist_prime=0;
    while(t<=m || !ist_prime){
        t++;
        if(is_prime(t)){
            ist_prime = 1;
            if(t<m) *p1=t;
            if(t>m) *p2=t;
        }
        else ist_prime=0;
    }
}

int main(){
    int m, p1=0, p2=0;
    scanf("%d", &m);
    primos(m, &p1, &p2);
    printf("%d\n%d", p1, p2);
    return EXIT_SUCCESS;
}