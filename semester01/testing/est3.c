#include <stdio.h>

struct ponto
{
    int x;
    int y;
};
typedef struct
{
    struct ponto p[3];
} triangle;


int main(){
    triangle t1;
    t1.p[0].x = 0;
    t1.p[1].y = 1;
    printf("%d/%d", t1.p[0].x, t1.p[1].y);
    return 0;
}