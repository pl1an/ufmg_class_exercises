#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[51];
    int age;
    char phone[21];
} data;

int main(int argc, char **argv){
    data filecontent;
    scanf("%s %d %s", filecontent.name, &filecontent.age, filecontent.phone);

    FILE *target_file = fopen(argv[1], "wb");
    fwrite(&filecontent, sizeof(filecontent), 1, target_file);
    
    fclose(target_file);

    return 0;
}