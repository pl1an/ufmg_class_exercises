#include <stdio.h>
#include <string.h>

int main(){
    char str1[20], str2[20];
    int stop_count=0;
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);
    
    for(int i=0; str1[i]!='\n'; i++){
        printf("%c", str1[i]);
    }
    for(int i=0; str2[i]!='\n'; i++){
        if(str2[i]!='\n') printf("%c", str2[i]);
    }

    return 0;
}