#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// basic info for drawing and generating fractal string
int teta_degrees = 60;
int max_recursion_level = 3;
int segment_lenght = 10;

// base axioma
char* base_axioma = "F-F++F-F";
// list of rules 
char* rules[] = {"F-F++F-F"};
int rule_number = 1;
// list of symbols that are substituted by the rules in the same position in their array
char substituition_symbols[] = {'F'};
// list of symbols that are removed at the end of the recursion
char removal_symbols[] = {'X', 'Y'};
int removal_symbol_number = 2;


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


// creates a fractal string
char* generate_fractal_string(){
    // initialazing fractal string
    char* fractal = malloc(1);
    fractal[0] = '\0';
    insert(base_axioma, fractal, 0);
    // initialazing rules lenght register
    int* rule_lenghts;
    rule_lenghts = malloc(sizeof(int)*(sizeof(rules)/sizeof(rules[0])));
    for(int i=0; i<(sizeof(rules)/sizeof(rules[0])); i++){
        rule_lenghts[i] = strlen(rules[i]);
    }
    // entering recursion level loop
    int added_characthers = 0;
    int fractal_lenght = 0;
    int rule_applied = 0;
    char* insert_characther_string;
    for(int recursion_level=1; recursion_level<max_recursion_level; recursion_level++){
        // resetting recurison level especific variables
        added_characthers = 0;
        fractal_lenght = strlen(fractal);
        // checking characthers in "fractal" string and comparing them to rules
        for(int characther=0; characther<fractal_lenght+added_characthers; characther++){
            // applying rules if characther matches
            rule_applied = 0;
            for(int rule=0; rule<rule_number; rule++){
                if(fractal[characther]==substituition_symbols[rule]){
                    rule_applied = 1;
                    replace(fractal, rules[rule], characther);
                    added_characthers += rule_lenghts[rule] - 1;
                }
            }
            // adding characthers to "fractal" string if no matching rule is found
            if(!rule_applied){
                insert_characther_string = &(fractal[characther]);
                insert(insert_characther_string, fractal, characther);
            }
        }
    }
    // removing all characthers in "removal_symbols" in the final "fractal" string version
    for(int symbol=0; symbol<removal_symbol_number; symbol++){
        fractal_lenght = strlen(fractal);
        for(int characther=0; characther<fractal_lenght; characther++){
            if(fractal[characther] == removal_symbols[symbol]){
                pop(fractal, characther);
            }
        }
    }
    // returning new fractal
    return fractal;
}


int main() {
}