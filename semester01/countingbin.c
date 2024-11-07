#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char filename[100];
    scanf("%s", filename);
    FILE *target_file = fopen(filename, "rb");
    char content[1];
    int counter=0;

    while(1==fread(content, sizeof(content), 1, target_file)){
        if(content[0]=='a') counter++;
    }

    printf("%d", counter);
    fclose(target_file);

    return 0;
}