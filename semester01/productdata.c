#include <stdio.h>
#include <string.h>

typedef struct{
    char name[51];
    char brand[51];
    float price;
} products;

int main(){
    products products[8];
    char brandnames[8][51];
    int brandquantity[8] = {0};
    float brandprice[8] = {0};
    char buffer[500];
    int found, nbrands=0;
    float meanmarker=0;

    for(int i=0; i<8; i++){
        fgets(buffer, 500, stdin);
        sscanf(buffer, "%s %s %f", products[i].name, products[i].brand, &products[i].price);
        meanmarker+=products[i].price;

        found=-1;
        for(int ii=0; ii<8; ii++){
            if(strcmp(products[i].brand, brandnames[ii])==0){
                found=ii;
            }
        }
        if(found+1){
            brandquantity[found]++;
            brandprice[found] += products[i].price;
        }
        else{
            strcpy(brandnames[nbrands], products[i].brand);
            nbrands++;
        }
    }

    for(int i=0; i<nbrands+1; i++){
        printf("%s %d\n", brandnames[i], brandquantity[i]);
    }
    printf("media total %.2f\n", meanmarker/8);
    for(int i=0; i<nbrands+1; i++){
        printf("media %s %.2f\n", brandnames[i], brandprice[i]/brandquantity[i]);
    }

    return 0;
}