#include <stdio.h>
#include <string.h>

int main(){
    char strr[20];
    fgets(strr, sizeof(strr), stdin);
    for(int i=strlen(strr); i!=-1; i--) {
        if(strr[i]!='\n') printf("%c", strr[i]);
    }

    return 0;
}