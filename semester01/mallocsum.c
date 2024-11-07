#include <stdio.h>
#include <stdlib.h>

void sumvector(int *v1, int *v2, int *output){
    for(int i=0; i<sizeof(v1)/sizeof(v1[0]); i++){
        output[i] = v1[i]+v2[i];
    }
}
int main(){
    int *v1, *v2, *out;
    int n;
    scanf("%d", &n);
    v1, v2, out = malloc(n*sizeof(int));
    for(int i=0; i<n*2; i++){
        if(n<2) scanf("%d", &v1[i]);
        else scanf("%d", &v2[i]);
    }
    sumvector(v1, v2, out);
    for(int i=0; i<n; i++){
        printf("%d ", out[i]);
    }
    free(v1); free(v2); free(out);
    return EXIT_SUCCESS;
}