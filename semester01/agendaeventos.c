#include <stdio.h>
#include <string.h>

typedef enum {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Mes;

typedef struct
{
    int day;
    Mes mes;
    int year;
} data;
typedef struct{
    char nome[100];
    char local[100];
    data data;
} evento;

void cadastrar_eventos(evento agenda[], int n){
    char buffer[250];
    int temp;
    for(int i=0; i<n; i++){
        getchar();
        fgets(buffer, 250, stdin);
        sscanf(buffer, "%s %s %d %d %d", agenda[i].nome, agenda[i].local, &agenda[i].data.day, &temp, &agenda[i].data.year);
        agenda[i].data.mes = temp;
    }
}
void emprimir_eventos(evento agenda[], data d, int n){
    int found=0;
    for (int i = 0; i < n; i++){
        if((agenda[i].data.day == d.day) && (agenda[i].data.mes == d.mes) && (agenda[i].data.year == d.year)){
            found = 1;
            printf("%s %s \n", agenda[i].nome, agenda[i].local);
        }
    }
    if(!found) printf("Nenhum evento encontrado!");
    
}

int main(){
    int n, temp;
    evento agenda[100];
    scanf("%d", &n);
    cadastrar_eventos(agenda, n);
    data d;
    scanf("%d %d %d", &d.day, &temp, &d.year);
    d.mes = temp;
    emprimir_eventos(agenda, d, n);
    return 0;
}