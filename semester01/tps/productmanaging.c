//includes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//definindo tipos

typedef struct item {
    int id;
    char name[50];
    char department[50];
    double price;
} item;

typedef struct node {
    item content;
    struct node *esq;
    struct node *dir;
} node;

typedef void (*functiontype)(node *basenode);


//functions

//fills the struct with default values
void filldefault(node *target){
    (*target).content.id = -1;
    strcpy((*target).content.name, "");
    (*target).content.price = 0;
    (*target).dir = NULL;
    (*target).esq = NULL;
}

//reads aline and removes \n
void read_string(FILE *target, char *buffer, int lim){
    fgets(buffer, lim, target);
    buffer[strcspn(buffer, "\n")] = '\0';
}

//recursively finds the right node to add an item
void insert(node *basenode, node *targetinsert){
    if((*basenode).content.id>(*targetinsert).content.id){
        if((*basenode).esq==NULL) (*basenode).esq = targetinsert; 
        else insert((*basenode).esq, targetinsert);
    }
    else{
        if((*basenode).dir==NULL) (*basenode).dir = targetinsert; 
        else insert((*basenode).dir, targetinsert);
    }
}

//loads file and creates the binary tree
node* load(FILE *loadfile, node *basenode, char *buffer){
    //creates the binary tree
    if(basenode==NULL){
        basenode = malloc(sizeof(node));
        filldefault(basenode);
        read_string(loadfile, buffer, 200);
        sscanf(buffer, "%d %s %s %lf", &(*basenode).content.id, (*basenode).content.name, (*basenode).content.department, &(*basenode).content.price);
        if(feof(loadfile)) return basenode;
    }
    //loads new data in binary tree
    node *loaded = malloc(sizeof(node));
    filldefault(loaded);
    read_string(loadfile, buffer, 200);
    sscanf(buffer, "%d %s %s %lf", &(*loaded).content.id, (*loaded).content.name, (*loaded).content.department, &(*loaded).content.price);
    insert(basenode, loaded);
    //calls another load if not in eof
    if(!feof(loadfile)) load(loadfile, basenode, buffer);
    //returns the base node (only useful for the first function call)
    return basenode;
}

//sorting algorithm
//creates a pivot in the list (between start and end elementes)
int partition(item *list, int start, int end){
    int pivotpos = end-1;
    item helper;
    for(int i=start; i<end-1; i++){
        if(list[i].price>=list[pivotpos].price){
            //breaking
            if(i>=pivotpos) break;
            //pivot goes one space to the back
            helper = list[pivotpos-1];
            list[pivotpos-1] = list[pivotpos];
            list[pivotpos] = helper;
            pivotpos--;
            //breaking
            if(i>=pivotpos) break;
            //item switches spaces with element after pivot
            helper = list[pivotpos+1];
            list[pivotpos+1] = list[i];
            list[i] = helper;
            i--;
        }
    }
    return pivotpos;
}
//main recursive sorting function
void quick(item *list, int start, int end){
    int pivot = partition(list, start, end);
    if(pivot+1<end-1) quick(list, pivot+1, end);
    if(start<pivot-1) quick(list, start, pivot);
}

//searches product by ID (1)
//recusively goes through the binary tree looking for specified ID
void findbyID(node *basenode, int targetid){
    //printing path & products
    printf("(%s) %s - R$ %.2lf\n", (*basenode).content.department, (*basenode).content.name, (*basenode).content.price);   
    //searching tree
    if((*basenode).content.id==targetid){}
    else if((*basenode).content.id>targetid && (*basenode).esq!=NULL) findbyID((*basenode).esq, targetid);
    else if((*basenode).content.id<targetid && (*basenode).dir!=NULL) findbyID((*basenode).dir, targetid);
    else printf("Produto nao encontrado!\n");
}
//calls findbyID
void showiditem(node *basenode){
    int targetid = 0;
    scanf("%d", &targetid); getchar();
    findbyID(basenode, targetid);
}

//searches product by department (2)
//finds and prints every item in specified department (returns 0 if no match)
int findbyDepartment(node *basenode, char *department, int found){
    if(!strcmp((*basenode).content.department, department)) found = 1;
    if((*basenode).esq!=NULL) found = findbyDepartment((*basenode).esq, department, found);
    if(!strcmp((*basenode).content.department, department)) printf("(%s) %s - R$ %.2lf\n", (*basenode).content.department, (*basenode).content.name, (*basenode).content.price);   
    if((*basenode).dir!=NULL) found = findbyDepartment((*basenode).dir, department, found);
    return found;
}
//calls findbyDepartment and prints info if there was no match
void showdepartmentitems(node *basenode){
    int found=0;
    char department[50];
    read_string(stdin, department, 50);
    found = findbyDepartment(basenode, department, found);
    if(!found) printf("Departamento vazio!\n");
}

//inserts new product (3)
void newProduct(node *basenode){
    char buffer[200];
    node *newnode = malloc(sizeof(node));
    filldefault(newnode);
    read_string(stdin, buffer, 200);
    sscanf(buffer, "%d %s %s %lf", &(*newnode).content.id, (*newnode).content.name, (*newnode).content.department, &(*newnode).content.price);
    //placing new product in tree
    insert(basenode, newnode);
}

//filters product by price (4)
//creates a non-sorted list with all products below budget
item* filterbyPrice(node *basenode, double budget, item *itemlist, int *itemlistsize){
    //adding item to list
    if((*basenode).content.price<=budget){
        (*itemlistsize)++;
        itemlist  = realloc(itemlist, sizeof(item)*(*itemlistsize));
        itemlist[(*itemlistsize)-1] = (*basenode).content;
    }
    //searching tree
    if((*basenode).esq!=NULL) itemlist = filterbyPrice((*basenode).esq, budget, itemlist, itemlistsize);
    if((*basenode).dir!=NULL) itemlist = filterbyPrice((*basenode).dir, budget, itemlist, itemlistsize);
    //returning
    return itemlist;
}
//sorts list from filterbyPrice and shows the elements in specified format
void showbudgetitems(node *basenode){
    item *itemlist = malloc(sizeof(item));
    int listsize = 0;
    double budget=0;
    scanf("%lf", &budget); getchar();
    //finding items
    itemlist = filterbyPrice(basenode, budget, itemlist, &listsize);
    if(listsize>0){
        //sorting list
        quick(itemlist, 0, listsize);
        //printing items
        for(int i=0; i<listsize; i++){
            printf("(%s) %s - R$ %.2lf\n", itemlist[i].department, itemlist[i].name, itemlist[i].price);
        }
    }
    else{
        printf("Sem resultados para o filtro!\n");
    }
    //freeing memory
    free(itemlist);
}

//frees the binary tree memory
void freetree(node *basenode){
    if((*basenode).dir !=NULL) freetree((*basenode).dir);
    if((*basenode).esq !=NULL) freetree((*basenode).esq);
    free(basenode);
}

//main application loop
void menu(node *basenode){
    int userchoice=0;
    functiontype operations[] = {showiditem, showdepartmentitems, newProduct, showbudgetitems, freetree};
    //printing menu  
    printf("1 - Procurar por ID\n");
    printf("2 - Procurar por Departamento\n");
    printf("3 - Inserir Produto\n");
    printf("4 - Filtrar por Preco\n");
    printf("5 - Sair\n");
    //function loop (notice that when user chooses 5, it runs freetree before going out of the loop)
    while(userchoice!=5){
        scanf("%d", &userchoice); getchar();
        operations[userchoice-1](basenode);
    }
}

//main function
int main(int argc, char **argv){ 
    //declaring variables
    node *binarytree = NULL;
    FILE *loadfile = fopen(argv[1], "r");
    char buffer[200];
    //loading and running app
    binarytree = load(loadfile, binarytree, buffer);
    menu(binarytree);
    //exiting
    return EXIT_SUCCESS;
}