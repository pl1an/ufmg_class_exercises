#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int teta_degrees = 60;
int max_recursion_level = 3;
char* base_axioma = "F-F++F-F";


// power functions for integers (to avoid floating point from math.h::pow)
int int_power(int base, int exp){
    int result = 1;
    for(int i=0; i<exp; i++) result*=base;
    return result;
}


// inserts "target" string into "origin" at the specified position
void insert(char* target, char* origin, int position) {
    int origin_length = strlen(origin);
    int target_length = strlen(target);
    char* new_inserted_string = malloc(sizeof(char) * (origin_length+target_length));
    // copy characters from "origin" up to "position"
    for (int i = 0; i < position; i++) {
        new_inserted_string[i] = origin[i];
    }
    // copy "target" into the new string
    for (int i = 0; i < target_length; i++) {
        new_inserted_string[position + i] = target[i];
    }
    // copy the remaining characters from "origin"
    for (int i = position; i < origin_length-1; i++) {
        new_inserted_string[target_length + i] = origin[i+1];
    }
    new_inserted_string[origin_length + target_length - 1] = '\0';
    strcpy(origin, new_inserted_string);
    free(new_inserted_string);
}


int find_total_fractal_string_lenght(){
    int total_fractal_string_lenght = 0;
    // finding the initial number of +, - and F in "base_axiama"
    int f_number = 0;
    int other_symbols_number = 0;
    for(int i=0; i<strlen(base_axioma); i++){
        if(base_axioma[i]=='F') f_number++;
        else other_symbols_number++;
    }
    // calculating final lenght of fractal string
    for(int i=1; i<=max_recursion_level; i++){
        total_fractal_string_lenght+=int_power(other_symbols_number, i);
    }
    total_fractal_string_lenght += int_power(f_number, max_recursion_level);
    return total_fractal_string_lenght; 
}

void generate_fractal_string(char* build, char* constructor, int total_fractal_string_lenght){
    int added_characthers = 0;
    for(int recursion_level=1; recursion_level<max_recursion_level; recursion_level++){
        strcpy(constructor, build);
        printf("\n\nNEW RECURSION LEVEL\nestimated lenght is %d\nconstructor is %s\n", total_fractal_string_lenght, constructor);
        added_characthers = 0;
        for(int i=0; i<strlen(constructor); i++){
            if(constructor[i]=='F'){
                printf("trying to insert base axioma at %d\n", i+added_characthers);
                insert(base_axioma, build, i+added_characthers);
                added_characthers += strlen(base_axioma)-1;
                printf("added new terms to build: %s\n", build);
            }
        }
    }
}


int main() {
    int total_fractal_string_lenght = find_total_fractal_string_lenght();
    // allocating memory
    char* fractal_string_build;
    fractal_string_build = malloc(sizeof(char)*(total_fractal_string_lenght+1));
    strcpy(fractal_string_build, base_axioma);
    char* fractal_string_constructor;
    fractal_string_constructor = malloc(sizeof(char)*(total_fractal_string_lenght+1));
    strcpy(fractal_string_constructor, base_axioma);
    // building fractal string
    generate_fractal_string(fractal_string_build, fractal_string_constructor, total_fractal_string_lenght);
    printf("%s", fractal_string_build);
    // freeing memory
    free(fractal_string_build);
    free(fractal_string_constructor);
    // ending program
    return 0;
}