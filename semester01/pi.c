#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int  main(){
    double error, ans=0;
    int counter=-1;
    scanf("%lf", &error);

    while(sqrt((M_PI-ans)*(M_PI-ans))>error){
        counter++;
        ans+=((double)4/(1+2*counter))*pow(-1, counter);
        //printf("%lf/", ans);
    }

    printf("%d", counter+1);

    return 0;
}