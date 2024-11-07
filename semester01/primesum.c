#include <stdio.h>
#include <math.h>
#include <string.h>

int isPrime(long long int target_number){
    if(target_number<2) return -1;
    else{
        for(int i=2; i<=sqrt(target_number); i++){
            if(target_number%i==0) return 0;
        }
    }
    
    return 1;
}

long long unsigned int sumPrimes(int times){
    long long unsigned int sum=0;
    int prime_counter, times_number=2;
    while(prime_counter<times){
        if(isPrime(times_number)){
            sum+=times_number;
            prime_counter++;
        }
        times_number++;
    }
    return sum;
}

int main(){
    char entrada[51];
    int target_times;
    while(fgets(entrada, 50, stdin) != NULL){
        entrada[strlen(entrada) - 1] = '\0';
        sscanf(entrada, "%d", &target_times);
        printf("%llu\n", sumPrimes(target_times));
    }
    return 0;
}