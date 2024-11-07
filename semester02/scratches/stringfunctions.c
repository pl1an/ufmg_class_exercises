#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// base info for fractal generation
int teta_degrees = 60;
int max_recursion_level = 3;
char* base_axioma = "F-F++F-F";


// all of the following string related functions do not return a new pointer
// they return the "target" pointer or NULL depending on the result of the memory allocation

// reallocates "new_size" extra charathers in a existing string
char* expand(char* target, int new_size){
    int previous_size = strlen(target);
    char* new_reallocated_string;
    // allocating and checking if it was performed successfully
    new_reallocated_string = (char*)realloc(target, sizeof(char)*(previous_size+new_size+1));
    if(new_reallocated_string==NULL) return NULL;
    // initialazing new spaces with zeros and adding '\0' at the end of reallocated string
    for(int i=0; i<new_size; i++){
        new_reallocated_string[previous_size+i] = '0';
    }
    new_reallocated_string[new_size+previous_size] = '\0';
    // returning
    return new_reallocated_string;
}

// inserts a "target" string at a especified position in a "origin" string
char* insert(char* target, char* origin, int position){
    // registering lenghts
    int origin_lenght = strlen(origin);
    int target_lenght = strlen(target);
    // creating expanded string from origin string
    char* new_inserted_string = expand(origin, target_lenght);
    if(new_inserted_string==NULL) return NULL;
    // copying existing characthers in "origin" string to new positions
    for(int i=position; i<origin_lenght; i++){
        new_inserted_string[i+target_lenght] = new_inserted_string[i];
    }
    // inserting "target" string at desired position
    for(int i=position; i<position+target_lenght; i++){
        new_inserted_string[i] = target[i-position];
    }
    // returning
    return new_inserted_string;
}

// removes a characther from "target" string in a specified position
char* pop(char* target, int position){
    char* new_pop_string;
    // removing desired characther
    for(int i=position; i<strlen(target)-1; i++){
        target[i] = target[i+1];
    }
    // making the string smaller by one characther
    new_pop_string = expand(target, -1);
    if(new_pop_string==NULL) return NULL;
    // returning
    return new_pop_string;
}

// replaces a characther at a specified "position" in "origin" string by the "target" string
char* replace(char* target, char* origin, int position){
    // inserting "target" at position
    char* new_replaced_string = insert(target, origin, position);
    if(new_replaced_string==NULL) return NULL;
    // removing characther previously at position
    new_replaced_string = pop(new_replaced_string, position+strlen(target));
    if(new_replaced_string==NULL) return NULL;
    // returning
    return new_replaced_string;
}

char* generate_fractal(char* new_fractal_string, char* base_fractal_string, int recursion_level){
    // stop condition
    if(recursion_level==max_recursion_level) return base_fractal_string;
    // replacing Fs
    for(int i=0; i<strlen(base_fractal_string); i++){
        if(base_fractal_string[i] == 'F') insert(base_axioma, new_fractal_string, strlen(new_fractal_string));
        else insert(&(base_fractal_string[i]), new_fractal_string, strlen(new_fractal_string));
    }
    // using this "base_fractal_string" as a new "new_fractal_string" for next recursion level
    expand(base_fractal_string, -strlen(base_fractal_string));
    // recursion loop
    generate_fractal(base_fractal_string, new_fractal_string, recursion_level+1);
}

int main(){
    // alocating the base fractal string and its new level
    char* base_fractal_string;
    strcpy(base_fractal_string, base_axioma);
    char* fractal_string = malloc(1);
    fractal_string[0] = '\0';
    // generating the fractal string recursevily;
    printf("%s\n", generate_fractal(fractal_string, base_fractal_string, 0));
    return 0;
}