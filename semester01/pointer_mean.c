#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void media(double vet[], int n, int *i){
    double media=0;
    for(int count=0; count<n; count++) media+=vet[count];
    media/=n;

    double dif=fabs(media-vet[0]);
    *i = 0;
    for(int count=1; count<n; count++){
        if(dif>fabs(media-vet[count])){
            dif = fabs(media-vet[count]);
            *i = count;
        }
    }
}

int main(){
    int i, n;
    double *vet;

    scanf("%d", &n);
    vet = (double*)malloc(sizeof(double)*n);

    for(int count=0; count<n; count++){
        scanf("%lf", &vet[count]);
    }

    media(vet, n, &i);
    printf("%d", i);

    free(vet);
    return EXIT_SUCCESS;
}