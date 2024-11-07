#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *target_file = fopen(argv[1], "r");
    char content;
    int counter=0;
    do{
        content = fgetc(target_file);
        if(content=='a') counter++;
    }while(content!=EOF);

    printf("%d", counter);
    fclose(target_file);

    return 0;
}