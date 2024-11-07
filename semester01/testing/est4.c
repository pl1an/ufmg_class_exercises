#include <stdio.h>
#include <string.h>
int main(){
    char *p;
    int limit;
    scanf("%d", &limit);
    fgets(p, limit, stdin);
    fputs(p, stdout);
} 