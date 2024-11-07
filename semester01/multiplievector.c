#include <stdio.h>

void imprime(int vetor[], int n){
    for (int i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void multiplica(int vetor[], int n, double v){
    for(int i=0; i<n; i++){
        vetor[i] *= v;
    }
}

int main(){
    int vetor[1000];
    int n;
    double v;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    scanf("%lf", &v);
    imprime(vetor, n);
    multiplica(vetor, n, v);
    imprime(vetor, n);
    multiplica(vetor, n, 1/v);
    imprime(vetor, n);
    return 0;
}