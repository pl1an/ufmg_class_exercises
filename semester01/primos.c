#include <stdio.h>
#include <math.h>
#include <string.h>

/*int main(){
    int a, b, prime=0;
    scanf("%d%d", &a, &b);

    for(int i=a/2; i<=b/2; i++){
        prime=0;
        int temp = ((2*i)-1);
        if(temp==1) printf("2\n");
        else{
            if(temp<a) temp = a;
            for(int ii=2; temp%ii!=0; ii++) if(ii==temp-1) prime=1;
        }
        if(prime) printf("%d\n", i*2-1);
    }

    return 0;
}*/

int isPrime(long long int target_number){
    if(target_number<2) return -1;
    else{
        for(int i=2; i<=sqrt(target_number); i++){
            if(target_number%i==0) return 0;
        }
    }
    
    return 1;
}

int main(){
    char entrada[51];
    long long int target;
    while(fgets(entrada, 50, stdin) != NULL){
        entrada[strlen(entrada) - 1] = '\0';
        sscanf(entrada, "%d", &target);
        printf("%d\n", isPrime(target));
    }
    return 0;
}