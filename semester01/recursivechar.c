#include <stdio.h>
#include <string.h>

int comparechar(char target, char *string, int n){
    if(n==0) return 0;
    else if(string[strlen(string)-n-1]==target) return 1 + comparechar(target, string, n-1);
    else return comparechar(target, string, n-1);
}

int main(){
    char string[100], target;
    fgets(string, 100, stdin);
    scanf("%c", &target);
    printf("%d", comparechar(target, string, strlen(string)-1));
    return 0;
}