#include <stdio.h>

int finbonacci(int a, int b, int n){
    if(n==3) return a+b;
    else return finbonacci(a+b, a, n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    if(n<3) printf("1");
    else printf("%d", finbonacci(1, 1, n));
    return 0;
}