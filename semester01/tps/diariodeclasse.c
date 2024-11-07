//importando pacotes --

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//definindo estruturas (e outros) --

typedef struct {
    char nome[100];
    int matricula;
    int nota[3];
} aluno;

typedef struct {
    char codigo[10];
    char nome[100];
    aluno alunos[6];
    int nalunos;
} turma;

typedef struct{
    char nome[100];
    int registro;
    turma turmas[2];
    int nturmas;
} professor;

typedef void (*functype)(professor *data, char *target_filename);


//functions --

//lê uma linha e remover o \n
void read_string(FILE *target, char *buffer, int lim){
    fgets(buffer, lim, target);
    buffer[strcspn(buffer, "\n")] = '\0';
}

//preenche o struct com valores default
void fillstruct(professor *data){
    strcpy((*data).nome, "none");
    (*data).registro = -1;
    (*data).nturmas = 0;
    for(int i=0; i<sizeof((*data).turmas)/sizeof((*data).turmas[0]); i++){
        strcpy((*data).turmas[i].nome, "NOT ASSIGNED");
        strcpy((*data).turmas[i].codigo, "NO CODE");
        (*data).turmas[i].nalunos = 0;
        for(int ii=0; ii<sizeof((*data).turmas[i].alunos)/sizeof((*data).turmas[i].alunos[0]); ii++){
            strcpy((*data).turmas[i].alunos[ii].nome, "none");
            (*data).turmas[i].alunos[ii].matricula = -1;
            (*data).turmas[i].alunos[ii].nota[0] = 0;
            (*data).turmas[i].alunos[ii].nota[1] = 0;
            (*data).turmas[i].alunos[ii].nota[2] = 0;
        }
    }
}

//carrega os dados do arquivo
void load(professor *data, char *filename){
    FILE *loadfile = fopen(filename, "r");
    char buffer[100];
    for(int loopcounter=0; loopcounter<3; loopcounter++){
        read_string(loadfile, buffer, 100);
        //le os dados do professor nas primeiras duas iterações do loop
        if(loopcounter==0) strcpy((*data).nome, buffer);
        if(loopcounter==1) sscanf(buffer, "%d", &(*data).registro);
        if(loopcounter==2){
            //lendo os dados das turmas
            sscanf(buffer, "%d", &(*data).nturmas);
            for(int i=0; i<(*data).nturmas; i++){
                read_string(loadfile, buffer, 100);
                strcpy((*data).turmas[i].nome, buffer);
                read_string(loadfile, buffer, 100);
                strcpy((*data).turmas[i].codigo, buffer);
            }
            //lendo os dados dos alunos
            for(int i=0; i<(*data).nturmas; i++){
                read_string(loadfile, buffer, 100);
                sscanf(buffer, "%d", &(*data).turmas[i].nalunos);
                for(int ii=0; ii<(*data).turmas[i].nalunos; ii++){
                    read_string(loadfile, buffer, 100);
                    strcpy((*data).turmas[i].alunos[ii].nome, buffer);
                    read_string(loadfile, buffer, 100);
                    sscanf(buffer, "%d", &(*data).turmas[i].alunos[ii].matricula);
                }
            }
        }
    }
    fclose(loadfile);
}

//retorna (para turma_position e aluno_position) a posição de uma turma de acordo com um código e a posição de um aluno de acordo com a matricula
void search_ta(professor *data, char *codigo, int matricula, int *turma_position, int *aluno_position){
    for(int i=0; i<(*data).nturmas; i++){
        if(!strcmp(codigo, (*data).turmas[i].codigo)){
            *turma_position = i;
        }
    }
    //procurando aluno
    for(int i=0; i<(*data).turmas[*turma_position].nalunos; i++){
        if(matricula==(*data).turmas[*turma_position].alunos[i].matricula){
            *aluno_position = i;
        }
    }
}

//retorna (para nota_final, conceito e situacao) a nota final, o conceito e a situacao de um aluno especificado pela turma_position e aluno_position
void calculate_finals(professor *data, int turma_position, int aluno_position, int *nota_final, char *conceito, char *situacao){
    //calculando nota final
    (*nota_final) = ((*data).turmas[turma_position].alunos[aluno_position].nota[0]+(*data).turmas[turma_position].alunos[aluno_position].nota[1]+(*data).turmas[turma_position].alunos[aluno_position].nota[2])/3;
    //retornando conceito e situacao
    if((*nota_final)<40){
        (*conceito) = 'F';
        strcpy(situacao, "Reprovado");
    }
    else if((*nota_final)<60){
        (*conceito) = 'E';
        strcpy(situacao, "Exame Especial");
    }
    else if((*nota_final)<70){
        (*conceito) = 'D';
        strcpy(situacao, "Aprovado");
    }
    else if((*nota_final)<80){
        (*conceito) = 'C';
        strcpy(situacao, "Aprovado");
    }
    else if((*nota_final)<90){
        (*conceito) = 'B';
        strcpy(situacao, "Aprovado");
    }
    else if((*nota_final)<=100){
        (*conceito) = 'A';
        strcpy(situacao, "Aprovado");
    }
}

//emprime info do professor (op1)
void prof_info(professor *data, char *target_filename){
    printf("Professor %s\n", (*data).nome);
    printf("Registro numero %d\n", (*data).registro);
    for(int i=0; i<(*data).nturmas; i++){
        printf("Turma %d: %s - %s, %d alunos\n", i+1, (*data).turmas[i].codigo, (*data).turmas[i].nome, (*data).turmas[i].nalunos);
    }
}

//emprime info do aluno (op2)
void aluno_info(professor *data, char *target_filename){
    char codigo[10];
    int matricula, nota_final, turma_position=0, aluno_position=0;
    char conceito, situacao[100];
    scanf("%d", &matricula); getchar();
    read_string(stdin, codigo, 10);
    //procurando turma e aluno (e calculando nota final e conceito)
    search_ta(data, codigo, matricula, &turma_position, &aluno_position);
    calculate_finals(data, turma_position, aluno_position, &nota_final, &conceito, situacao);
    //emprimindo
    printf("Aluno: %s\n", (*data).turmas[turma_position].alunos[aluno_position].nome);
    printf("Matricula: %d\n", matricula);
    printf("Prova 1: %d / Prova 2: %d / Prova 3: %d\n", (*data).turmas[turma_position].alunos[aluno_position].nota[0], (*data).turmas[turma_position].alunos[aluno_position].nota[1], (*data).turmas[turma_position].alunos[aluno_position].nota[2]);
    printf("Nota Final: %d - Conceito %c\n", nota_final, conceito);
}

//insere aluno (op3)
void inserir_aluno(professor *data, char *target_filename){
    char nome[100], codigo[10];
    int matricula;
    read_string(stdin, nome, 100);
    scanf("%d", &matricula); getchar();
    read_string(stdin, codigo, 10);
    //colocando o aluno na turma
    for(int i=0; i<(*data).nturmas; i++){
        if(!strcmp(codigo, (*data).turmas[i].codigo)){
            strcpy((*data).turmas[i].alunos[(*data).turmas[i].nalunos].nome, nome);
            (*data).turmas[i].alunos[(*data).turmas[i].nalunos].matricula = matricula;
            (*data).turmas[i].alunos[(*data).turmas[i].nalunos].nota[0] = 0;
            (*data).turmas[i].alunos[(*data).turmas[i].nalunos].nota[1] = 0;
            (*data).turmas[i].alunos[(*data).turmas[i].nalunos].nota[2] = 0;
            (*data).turmas[i].nalunos++;
        }
    }
}

//lanca notas (op4)
void inserir_notas(professor *data, char *target_filename){
    char codigo[10];
    int matricula, turma_position=0, aluno_position=0;
    int nota1, nota2, nota3;
    scanf("%d", &matricula); getchar();
    read_string(stdin, codigo, 10);
    scanf("%d %d %d", &nota1, &nota2, &nota3); getchar();
    //procurando turma e aluno
    search_ta(data, codigo, matricula, &turma_position, &aluno_position);
    //atribuindo os pontos
    (*data).turmas[turma_position].alunos[aluno_position].nota[0] = nota1;
    (*data).turmas[turma_position].alunos[aluno_position].nota[1] = nota2;
    (*data).turmas[turma_position].alunos[aluno_position].nota[2] = nota3;
}

//emprime info da turma (op5)
void turma_info(professor *data, char *target_filename){
    char codigo[10];
    int turma_position=0, aluno_position=0;
    read_string(stdin, codigo, 10);
    //procurando a turma
    search_ta(data, codigo, 0, &turma_position, &aluno_position);
    //emprimindo
    printf("Informacoes da turma %s - %s:\n", (*data).turmas[turma_position].codigo, (*data).turmas[turma_position].nome);
    printf("%d alunos\n", (*data).turmas[turma_position].nalunos);
    for(int i=0; i<(*data).turmas[turma_position].nalunos; i++){
        printf("Aluno: %s\n", (*data).turmas[turma_position].alunos[i].nome);
        printf("Matricula: %d\n", (*data).turmas[turma_position].alunos[i].matricula);
    }
}

//emprime info da turma + nota final, conceito e situacao dos alunos (op6)
void situacao_turma(professor *data, char *target_filename){
    char conceito, situacao[100], codigo[10];
    int nota_final, turma_position=0, aluno_position=0;
    read_string(stdin, codigo, 10);
    //procurando a turma
    search_ta(data, codigo, 0, &turma_position, &aluno_position);
    //emprimindo
    printf("Situacao na Turma %s - %s\n", (*data).turmas[turma_position].codigo, (*data).turmas[turma_position].nome);
    for(int i=0; i<(*data).turmas[turma_position].nalunos; i++){
        calculate_finals(data, turma_position, i, &nota_final, &conceito, situacao);
        printf("Aluno: %s\n", (*data).turmas[turma_position].alunos[i].nome);
        printf("Matricula: %d\n", (*data).turmas[turma_position].alunos[i].matricula);
        printf("Nota final : %d - Conceito: %c\n", nota_final, conceito);
        printf("Situacao: %s\n", situacao);
    }
}

//importa os dados para outro arquivo (op7)
void import_data(professor *data, char *target_filename){
    FILE *file = fopen(target_filename, "w");
    int nota_final;
    char conceito, situacao[100];
    //retornando dados para o arquivo
    fprintf(file, "DADOS EXPORTADOS\n");
    fprintf(file, "\nProfessor %s - Registro %d\n", (*data).nome, (*data).registro);
    for(int i=0; i<(*data).nturmas; i++){
        fprintf(file, "\nTurma %s - %s\n", (*data).turmas[i].codigo, (*data).turmas[i].nome);
        for(int ii=0; ii<(*data).turmas[i].nalunos; ii++){
            calculate_finals(data, i, ii, &nota_final, &conceito, situacao);
            fprintf(file, "Aluno: %s\n", (*data).turmas[i].alunos[ii].nome);
            fprintf(file, "Matricula: %d\n", (*data).turmas[i].alunos[ii].matricula);
            fprintf(file, "Nota Final: %d - Conceito %c - %s\n", nota_final, conceito, situacao);
        }
    }
    fclose(file);
}

//cria o menu e faz a chamada da maioria das funcoes
void main_menu(professor *data, char *target_filename){
    functype funcarray[7] = {&prof_info, &aluno_info, &inserir_aluno, &inserir_notas, &turma_info, &situacao_turma, &import_data};
    //emprimindo menu
    printf("1 - Informacoes do Professor\n");
    printf("2 - Informacoes do Aluno\n");
    printf("3 - Inserir Aluno\n");
    printf("4 - Lancar Notas\n");
    printf("5 - Informacoes da Turma\n");
    printf("6 - Situacao dos Alunos\n");
    printf("7 - Exportar Dados\n");
    //main application loop
    int choice=0;
    while(choice!=7){
        scanf("%d", &choice); getchar();
        funcarray[choice-1](data, target_filename);
    }
}

//main function
int main(int argc, char **argv){
    professor data;
    fillstruct(&data);
    load(&data, argv[1]);
    main_menu(&data, argv[2]);
    return EXIT_SUCCESS;
}