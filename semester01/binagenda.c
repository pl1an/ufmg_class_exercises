#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    char telefone[20];
} agenda_format;

int filldefault(agenda_format *full){
    for(int i=0; i<100; i++){
        strcpy(full[i].nome, "");
        strcpy(full[i].telefone, "");
        full[i].idade = -1;
    }
}
int has_space(int *vague){
    for(int i=0; i<100; i++){
        if(vague[i]==0){
            return i;
        }
    }
    return -1;
}
int loadfull(char *filename, int *vague){
    //defaulting all data
    agenda_format all_data[100];
    filldefault(all_data);
    //reading file
    FILE *file = fopen(filename, "rb");
    fread(all_data, sizeof(agenda_format), 100, file);
    //setting vague
    for(int i=0; i<100; i++){
        if(all_data[i].idade==-1) vague[i]=0;
        else vague[i]=1;
    }
    //closing file
    fclose(file);
}
int showall(char *filename){
    //reading file
    FILE *file = fopen(filename, "rb");
    agenda_format full_agenda[100];
    filldefault(full_agenda);
    int numberr = fread(full_agenda, sizeof(agenda_format), 100, file);
    fclose(file);
    //printing info
    for(int i=0; i<sizeof(full_agenda)/sizeof(full_agenda[0]); i++){
        printf("nome: %s / idade: %d / telefone: %s\n", full_agenda[i].nome, full_agenda[i].idade, full_agenda[i].telefone);
    }
    printf("readed %d registers", numberr);
}

int inserir(char *filename, int *vague){
    //checking if it has space
    int vague_position = has_space(vague);
    if(vague_position==-1){
        printf("Espaco insuficiente\n");
        return EXIT_FAILURE;
    };
    //defaulting full agenda
    agenda_format full_agenda[100];
    filldefault(full_agenda);
    //reading file
    FILE *file = fopen(filename, "rb");
    fread(full_agenda, sizeof(agenda_format), 100, file);
    fclose(file);
    //getting data to append
    agenda_format data;
    scanf("%s %d %s", data.nome, &data.idade, data.telefone);
    //appending data to list
    full_agenda[vague_position] = data;
    vague[vague_position] = 1;
    //overwriting file
    file = fopen(filename, "wb");
    fwrite(full_agenda, sizeof(agenda_format), 100, file);
    fclose(file);
    printf("Registro %s %d %s inserido\n", data.nome, data.idade, data.telefone);
}
int alterar(char *filename){
    //reading file
    FILE *file = fopen(filename, "rb");
    agenda_format full_agenda[100];
    filldefault(full_agenda);
    fread(full_agenda, sizeof(agenda_format), 100, file);
    fclose(file);
    //selecting target and alterations
    char target[100];
    scanf("%s", target);
    agenda_format data;
    scanf("%s %d %s", data.nome, &data.idade, data.telefone);
    //changing data
    int found=0;
    for(int i=0; i<100; i++){
        if(!strcmp(full_agenda[i].nome, target)){
            full_agenda[i] = data;
            printf("Registro %s %d %s alterado\n", full_agenda[i].nome, full_agenda[i].idade, full_agenda[i].telefone);
            found=1;
            break;
        }
    }
    if(found==0) printf("Registro %s invalido\n", target);
    //overwriting file
    file = fopen(filename, "wb");
    fwrite(full_agenda, sizeof(agenda_format), 100, file);
    fclose(file);
}
int excluir(char *filename, int *vague){
    //reading file
    FILE *file = fopen(filename, "rb");
    agenda_format full_agenda[100];
    filldefault(full_agenda);
    fread(full_agenda, sizeof(agenda_format), 100, file);
    fclose(file);
    //selecting target
    char target[100];
    scanf("%s", target);
    //changing data
    int found=0;
    for(int i=0; i<100; i++){
        if(!strcmp(full_agenda[i].nome, target)){
            printf("Registro %s %d %s excluido\n", full_agenda[i].nome, full_agenda[i].idade, full_agenda[i].telefone);
            strcpy(full_agenda[i].nome, "");
            strcpy(full_agenda[i].telefone, "");
            full_agenda[i].idade = -1;
            vague[i] = 0;
            found=1;
            break;
        }
    }
    if(found==0) printf("Registro %s invalido\n", target);
    //overwriting file
    file = fopen(filename, "wb");
    fwrite(full_agenda, sizeof(agenda_format), 100, file);
    fclose(file);
}
int exibir(char *filename){
    //reading file
    FILE *file = fopen(filename, "rb");
    agenda_format full_agenda[100];
    filldefault(full_agenda);
    fread(full_agenda, sizeof(agenda_format), 100, file);
    //searching and showing data
    char target[100];
    int found=0;
    scanf("%s", target);
    for(int i=0; i<100; i++){
        if(!strcmp(full_agenda[i].nome, target)){
            printf("Registro %s %d %s exibido\n", full_agenda[i].nome, full_agenda[i].idade, full_agenda[i].telefone);
            found=1;
            break;
        }
    }
    if(found==0) printf("Registro %s invalido\n", target);
    // closing file
    fclose(file);
}

int main(){
    char filename[100];
    scanf("%s", filename);
    //loading vague
    FILE *file = fopen(filename, "ab");
    fclose(file); 
    int vague[100] = {0};
    loadfull(filename, vague);

    char entrada[51];
    while(fgets(entrada, 50, stdin) != NULL){
        entrada[strlen(entrada) - 1] = '\0';
        if(!strcmp(entrada, "Inserir")) inserir(filename, vague);
        if(!strcmp(entrada, "Exibir")) exibir(filename);
        if(!strcmp(entrada, "Alterar")) alterar(filename);
        if(!strcmp(entrada, "Excluir")) excluir(filename, vague);
        if(!strcmp(entrada, "/showall")) showall(filename);
        if(!strcmp(entrada, "/loadfull")) loadfull(filename, vague);
    }

    return EXIT_SUCCESS;
}