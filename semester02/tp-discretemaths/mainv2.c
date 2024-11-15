#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// basic info for drawing and generating fractal string
int teta_degrees = 60;
int max_recursion_level = 3;
int segment_lenght = 10;

// base axioma
char* base_axioma;
// list of rules 
char** rules;
int rule_number = 0;
// list of symbols that are substituted by the rules in the same position in their array
char* substituition_symbols;
// list of symbols that are removed at the end of the recursion
char* removal_symbols;
int removal_symbol_number = 0;


// power function for integers (to avoid floating point from math.h::pow)
int int_power(int base, int exp){
    int result = 1;
    for(int i=0; i<exp; i++) result*=base;
    return result;
}


// inserts "target" string into "origin" at the specified position
void insert(char* target, char* origin, int position) {
    int base_lenght = strlen(origin);
    int target_lenght = strlen(target);
    memmove(origin + position + target_lenght, origin + position, base_lenght - position + 1);
    memcpy(origin + position, target, target_lenght);
}

// removes a characther at a specified position in a "target" string
void pop(char* target, int position){
    int target_lenght = strlen(target);
    for(int i=position; i<target_lenght; i++){
        target[i] = target[i+1];
    }
}

// replaces a characther in "position" at "origin" string with a "target" string
void replace(char* origin, char* target, int position){
    pop(origin, position);
    insert(target, origin, position);
}

// removes all instances of the "target_characther" in "origin" string
void remove_characthers(char target_characther, char* origin){
    int origin_lenght = strlen(origin);
    for(int i=0; i<origin_lenght; i++){
        if(origin[i] == target_characther){
            pop(origin, i);
            i--;
        }
    }
}


// approximates an upper limit to "fractal" string lenght
int generate_fractal_lenght(){
    int biggest_characther_count = 0;
    biggest_characther_count = strlen(rules[0]);
    for(int i=1; i<rule_number; i++){
        if(biggest_characther_count<strlen(rules[i])) biggest_characther_count = strlen(rules[i]);
    }
    if(biggest_characther_count<strlen(base_axioma)) biggest_characther_count = strlen(base_axioma);
    return int_power(biggest_characther_count, max_recursion_level);
}

// creates a fractal string
char* generate_fractal_string(){
    // initialazing fractal string
    char* fractal = malloc(generate_fractal_lenght());
    fractal[0] = '\0';
    insert(base_axioma, fractal, 0);
    printf("FRACTAL INITIALIZED: %s\n", fractal);
    // initialazing rules lenght register
    int* rule_lenghts;
    rule_lenghts = malloc(sizeof(int)*(sizeof(rules)/sizeof(rules[0])));
    for(int i=0; i<(sizeof(rules)/sizeof(rules[0])); i++){
        rule_lenghts[i] = strlen(rules[i]);
    }
    printf("RULE LENGHTS INITIALIZED: ");
    for(int i=0; i<sizeof(rules)/sizeof(rules[0]); i++){
        printf("%d, ", rule_lenghts[i]);
    }
    printf("\n");
    // entering recursion level loop
    int added_characthers = 0;
    int fractal_lenght = 0;
    int rule_applied = 0;
    char* insert_characther_string;
    for(int recursion_level=1; recursion_level<max_recursion_level; recursion_level++){
        printf("\nENTERING RECURSION LEVEL %d\n", recursion_level);
        printf("BASE FRACTAL: %s\n", fractal);
        // resetting recurison level especific variables
        added_characthers = 0;
        fractal_lenght = strlen(fractal);
        // checking characthers in "fractal" string and comparing them to rules
        for(int characther=0; characther<fractal_lenght; characther++){
            // applying rules if characther matches
            rule_applied = 0;
            for(int rule=0; rule<rule_number; rule++){
                if(fractal[characther+added_characthers]==substituition_symbols[rule] && !rule_applied){
                    printf("APPLYING RULE - %s\n", rules[rule]);
                    rule_applied = 1;
                    replace(fractal, rules[rule], characther+added_characthers);
                    added_characthers += rule_lenghts[rule] - 1;
                    printf("ADDED %d CHARACTHERS THIS RECURSION LEVEL: %s\n", added_characthers, fractal);
                }
            }
        }
    }
    free(rule_lenghts);
    // removing all characthers in "removal_symbols" in the final "fractal" string version
    fractal_lenght = strlen(fractal);
    for(int characther=0; characther<fractal_lenght; characther++){
        for(int symbol=0; symbol<removal_symbol_number; symbol++){
            if(fractal[characther]==removal_symbols[symbol]){
                pop(fractal, characther);
                characther--;
                fractal_lenght--;
            }
        }
    }
    // returning new fractal
    return fractal;
}


// gets the inputs necessary to generate the fractal from the user
int get_inputs(){
    char buffer[99];
    // reading base axioma
    printf("BASE AXIOMA: ");
    scanf("%99s", buffer);
    base_axioma = malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(base_axioma, buffer);
    getchar();
    // allocating memory for the rules
    printf("\ninput the number of rules: ");
    scanf("%d", &rule_number);
    getchar();
    rules = malloc(sizeof(char*)*rule_number);
    substituition_symbols = malloc(sizeof(char)*rule_number);
    // reading rules 
    for(int i=0; i<rule_number; i++){
        printf("input substituition symbol for rule %d: ", i+1);
        scanf("%c", &substituition_symbols[i]);
        printf("input rule %d: ", i+1);
        scanf("%99s", buffer);
        getchar();
        rules[i] = malloc(sizeof(char)*(strlen(buffer)+1));
        strcpy(rules[i], buffer);
    }
    // reading removal symbols
    printf("\ninput the number of symbols to be removed: ");
    scanf("%d", &removal_symbol_number);
    getchar();
    removal_symbols = malloc(sizeof(char)*removal_symbol_number);
    for(int i=0; i<removal_symbol_number; i++){
        printf("input removal symbol %d: ", i+1);
        scanf("%c", &removal_symbols[i]);
        getchar();
    }
    // reading the last inputs: "max_recursion_level"
    printf("\n\nINPUT THE MAX RECUSION LEVEL: ");
    scanf("%d", &max_recursion_level);
    getchar();
    char confirmation;
    printf("\nGENERATE FRACTAL (S/N): ");
    scanf("%c", &confirmation);
    if(confirmation == 's' || confirmation == 'S') return 1;
    else return 0;

}

// displays the values of the global variables - debug
void read_variables(){
    printf("\nmax recursion level: %d\n", max_recursion_level);
    printf("base axioma: %s\n", base_axioma);
    for(int i=0; i<rule_number; i++){
        printf("rule %d: %c -> %s\n", i+1, substituition_symbols[i], rules[i]);
    }
    for(int i=0; i<removal_symbol_number; i++){
        printf("removal symbol %d: %c\n", i+1, removal_symbols[i]);
    }
}

// frees all of the memory used in the code
void free_all(char* fractal){
    free(fractal);
    free(base_axioma);
    for(int i=0; i<rule_number; i++){
        free(rules[i]);
    }
    free(rules);
    free(substituition_symbols);
    free(removal_symbols);
}


int main() {
    char* fractal;
    get_inputs();
    fractal = generate_fractal_string();
    printf("%s", fractal);
    free_all(fractal);
    return 0;
}