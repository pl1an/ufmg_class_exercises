#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    long long int matrix[2][5][5] = {0}, summ[5][5];
    int tencounter=0, xcounter=0, ycounter=0;
    long long int number=0;
    char content;

    char filename[100];
    scanf("%s", filename);
    FILE *target_file = fopen(filename, "rb");

    while(fscanf(target_file, "%lld", &number)==1){
        matrix[tencounter][ycounter][xcounter] = number;
        xcounter++;
        if(xcounter>4){
            xcounter=0;
            ycounter++;
        }
        if(ycounter>4){
            ycounter=0;
            tencounter++;
        }
    }

    for (int i = 0; i < 5; i++){
        for (int ii = 0; ii < 5; ii++){
            summ[i][ii] = matrix[0][i][ii] + matrix[1][i][ii];
        }
    }
    
    for(int i=0; i<5; i++){
        for(int ii=0; ii<5; ii++){
            printf("%lld ", summ[i][ii]);
        }
        printf("\n");
    }
    
    fclose(target_file);

    return 0;
}