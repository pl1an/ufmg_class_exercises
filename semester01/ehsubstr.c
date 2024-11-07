#include <stdio.h>
#include <string.h>

int compare(char *t1, char *t2){
    for(int i=0; i<strlen(t2); i++){
        if(t1[i]!=t2[i]) return 0;
    }
    return 1;
}

void copy(char *o, char *t, int max){
    int ns=0;
    for(int i=0; i<max; i++){
        if(o[i]!='\n') t[i-ns] = o[i];
        else ns++;
    }
    t[max] = '\0';
}

void invert(char *o, char *t){
    char result[30];
    for(int i=0; i<strlen(o); i++){
        result[i] = o[strlen(o)-1-i];
    }
    result[strlen(o)]='\0';
    copy(result, t, strlen(result));
}

int main(){
    char s1[30], s2[30], s3[30];
    int subs = 0;
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);

    invert(s1, s1);
    s2[strlen(s2)-1]='\0';
    for(int i=0; strlen(s2)<strlen(s1)-i; i++){
        copy(s1, s3, strlen(s1)-1-i);
        invert(s3, s3);
        if(compare(s3, s2)) subs = 1;
    }

    if(subs) printf("É substring");

    return 0;
}