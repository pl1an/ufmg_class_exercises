#include <stdio.h>
#include <string.h>

typedef struct
{
    /* data */
    unsigned int age;
    char name[51];
    float salary;
    char rua[51];
    unsigned int numero;
    char estado[51];
} personaldata;
//kojimaplaya

int main(){
    personaldata vector[5];
    personaldata temporary;
    int counter=0, found;
    char buffer[1001];

    while(1){
        fgets(buffer, 9, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        if(strcmp(buffer, "inserir\0") == 0){
            if(counter<5){
                fgets(buffer, 1000, stdin);
                sscanf(buffer, "%s %d %f %s %d %s", vector[counter].name, &vector[counter].age, &vector[counter].salary, vector[counter].rua, &vector[counter].numero, vector[counter].estado);
                printf("Registro %s %d %.2f %s %d %s inserido\n", vector[counter].name, vector[counter].age, vector[counter].salary, vector[counter].rua, vector[counter].numero, vector[counter].estado);
                counter++;
            }
            else{
                fgets(buffer, 1000, stdin);
                printf("Espaco insuficiente\n");
            }
        }

        else if(strcmp(buffer, "mostrar\0") == 0){
            found=-1;
            fgets(buffer, 50, stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            for(int i=0; i<sizeof(vector)/sizeof(vector[0]); i++){
                if(strcmp(buffer, vector[i].name)==0){
                    found=i;
                }
            }
            if(found+1){
                printf("Registro %s %d %.2f %s %d %s\n", vector[found].name, vector[found].age, vector[found].salary, vector[found].rua, vector[found].numero, vector[found].estado);
            }
            else{
                printf("Registro ausente\n");
            }
        }

        else if(strcmp(buffer, "alterar\0")==0){
            fgets(buffer, 1000, stdin);
            sscanf(buffer, "%s %d %f %s %d %s", temporary.name, &temporary.age, &temporary.salary, temporary.rua, &temporary.numero, temporary.estado);
            found=-1;
            for(int i=0; i<sizeof(vector)/sizeof(vector[0]); i++){
                if(strcmp(temporary.name, vector[i].name)==0){
                    vector[i] = temporary;
                    found=i;
                }
            }
            if(found+1){
                printf("Registro %s %d %.2f %s %d %s alterado\n", vector[found].name, vector[found].age, vector[found].salary, vector[found].rua, vector[found].numero, vector[found].estado);
            }
            else{
                printf("Registro ausente para alteracao\n");
            }
        }
        
        else{
            break;
        }
    }

    return 0;
}