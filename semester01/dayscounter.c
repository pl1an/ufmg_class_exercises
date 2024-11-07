#include <stdio.h>
#include <string.h>

// retrun days related to 17/09/2020
int returnDays(int day, int month, int year){
    int diasAnoComum[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int diasAnoBissexto[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int reset=0;
    int days_counter = 0;
    for(int i=0; i<2020-year+1; i++){
        if(((year+i) % 4 == 0 && (year+i) % 100 != 0) || (year+i)%400==0){
            for(int ii=month-1; ii<12; ii++){
                if(month && reset==0 && ii==month-1 && ii==8 && year==2020){
                    days_counter+=17-day;
                    break;
                }
                else if(month && reset==0 && ii==month-1){
                    days_counter+=diasAnoBissexto[ii]-day;
                }
                else if(i==2020-year && ii==8){
                    days_counter+=17;
                    break;
                }
                else days_counter+=diasAnoBissexto[ii];
            }
        }
        else{
            for(int ii=month-1; ii<12; ii++){
                if(month && reset==0 && ii==month-1 && ii==8 && year==2020){
                    days_counter+=17-day;
                    break;
                }
                else if(month && reset==0 && ii==month-1) {
                    days_counter+=diasAnoComum[ii]-day;
                }
                else if(i==2020-year && ii==8){
                    days_counter+=17;
                    break;
                }
                else days_counter+=diasAnoComum[ii];
            }
        }
        month=1;
        reset=1;
    }

    return days_counter+1;
}

int main(){
    char entrada[51];
    int d=1, m=1, y=1;
    while(fgets(entrada, 50, stdin) != NULL){
        entrada[strlen(entrada) - 1] = '\0';
        sscanf(entrada, "%d %d %d", &d, &m, &y);
        if(d && m && y) printf("%d\n", returnDays(d, m, y));
    }
    return 0;
}