#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    char filecontent[100];
    scanf("%s", filecontent);
    FILE *target_file = fopen(argv[1], "wb");

    fwrite(filecontent, sizeof(filecontent), 1, target_file);
    
    fclose(target_file);

    return 0;
}