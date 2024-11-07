#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    FILE *arquivo = fopen(argv[1], "w");
    fprintf(arquivo, "hello world");
    fclose(arquivo);
}