#include <stdio.h>
#include <string.h>

int main(){
    char t[30];
    char c1, c2;

    fgets(t, sizeof(t), stdin);
    scanf("%c%c%c", &c1, &c2, &c2);
    for(int i=0; i<strlen(t); i++) if(t[i]==c1) {t[i] = c2; break;}
    fputs(t, stdout);
    return 0;
}