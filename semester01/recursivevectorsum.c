#include <stdio.h>
#include <stdlib.h>

int recursivesum(int *vec, int n, int pos){
    if(pos!=n-1) return vec[pos] + recursivesum(vec, n, pos+1);
    else return vec[pos];
}

int main(){
    int *vec, n;
    scanf("%d", &n);
    vec = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        scanf("%d", &vec[i]);
    }
    printf("%d", recursivesum(vec, n, 0));
    return 0;
}