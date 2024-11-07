#include <stdio.h>
#include <math.h>

typedef struct 
{
    double len_sepala;
    double wid_sepala;
    double len_petala;
    double wid_petala;
    char type[50];

} iris;


int main(){
    iris regi[1000];
    iris target;
    char buffer[100];
    int n;
    //reading data
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++){
        fgets(buffer, 100, stdin);
        sscanf(buffer, "%lf %lf %lf %lf %s", &regi[i].len_sepala, &regi[i].wid_sepala, &regi[i].len_petala, &regi[i].wid_petala, regi[i].type);
    }
    scanf("%lf %lf %lf %lf", &target.len_sepala, &target.wid_sepala, &target.len_petala, &target.wid_petala);
    //calculating euclidian distance
    double min;
    int tpos=0;
    min = sqrt(pow(regi[0].len_sepala-target.len_sepala, 2)+pow(regi[0].wid_sepala-target.wid_sepala, 2)+pow(regi[0].len_petala-target.len_petala, 2)+pow(regi[0].wid_petala-target.wid_petala, 2));
    for (int i = 0; i < n; i++){
        if((sqrt(pow(regi[i].len_sepala-target.len_sepala, 2)+pow(regi[i].wid_sepala-target.wid_sepala, 2)+pow(regi[i].len_petala-target.len_petala, 2)+pow(regi[i].wid_petala-target.wid_petala, 2)))<min){
            min = (sqrt(pow(regi[i].len_sepala-target.len_sepala, 2)+pow(regi[i].wid_sepala-target.wid_sepala, 2)+pow(regi[i].len_petala-target.len_petala, 2)+pow(regi[i].wid_petala-target.wid_petala, 2)));
            tpos = i;
        }
    }
    printf("%s\n", regi[tpos].type);
    
    return 0;
}