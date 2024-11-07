#include <stdio.h>
#include <string.h>

int isBissexto(int target_year){
    if((target_year%4 == 0 && target_year%100 != 0) || target_year%400==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char entrada[51];
    int year;
    while(fgets(entrada, 50, stdin) != NULL){
        entrada[strlen(entrada) - 1] = '\0';
        sscanf(entrada, "%d", &year);
        printf("%d\n", isBissexto(year));
    }
    return 0;
}