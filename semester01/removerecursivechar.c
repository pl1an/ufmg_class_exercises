#include <stdio.h>
#include <string.h>

void erasechar(char target, char *string, int n){
    printf("%d: comparing %c to %c\n", n, target, string[strlen(string)-n]);
    if(n==0);
    else if(string[strlen(string)-n]==target){
        for(int i=strlen(string)-n; i<strlen(string); i++){
            if(i==strlen(string)-1){
                string[i]='\0';
            }
            else{
                string[i] = string[i+1];
            }
        }
        erasechar(target, string, n-1);
    }
    else{
        erasechar(target, string, n-1);
    }
}

int main(){
    char string[100], target;
    fgets(string, 100, stdin);
    scanf("%c", &target);
    erasechar(target, string, strlen(string));
    fputs(string, stdout);
    return 0;
}