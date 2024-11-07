#include <stdio.h>
#include <math.h>

int main(){
    int matrix[2][5][5] = {0}, summ[5][5];

    for (int i = 0; i < 5; i++){
        for (int ii = 0; ii < 5; ii++){
            summ[i][ii] = matrix[0][i][ii] + matrix[1][i][ii];
        }
    }

    for(int i=0; i<5; i++){
        for(int ii=0; ii<5; ii++){
            printf("%d", summ[i][ii]);
        }
        printf("\n");
    }

    return 0;
}