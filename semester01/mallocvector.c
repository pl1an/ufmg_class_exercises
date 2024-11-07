#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, *nn;
    nn = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &nn[i]);
        printf("%d\n", nn[i]);
    }
    free(nn);
    return 0;
}