#include <stdio.h>
#include <stdlib.h>

int main(){
    int lines, columns;
    int **m;
    scanf("%d %d", &lines, &columns);
    m = malloc(lines*sizeof(int*));
    for (int i = 0; i < lines; i++){
        m[i] = malloc(columns*sizeof(int));
        for(int ii=0; ii<columns; ii++){
            scanf("%d", &m[i][ii]);
        }
    }
    for(int i=0; i<lines; i++){
        for (int ii = 0; ii < columns; ii++){
            printf("%d ", m[i][ii]);
        }
        printf("\n");
    }
    for(int i=0; i<lines; i++){
        free(m[i]);
    }
    free(m);
    return 0;
}