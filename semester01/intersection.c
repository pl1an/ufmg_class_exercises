#include <stdio.h>

int main(){
    int n1, n2, nt;
    int students[1000];

    scanf("%d", &n1);
    for(int i=0; i<n1; i++){
        scanf("%d", &nt);
        students[i] = nt;
    }

    scanf("%d", &n2);
    for(int i=n1; i<n2+n1; i++){
        scanf("%d", &nt);
        students[i] = nt;
    }

    for(int i1=0; i1<n1; i1++){
        for(int i2=n1; i2<n2+n1; i2++){
            if(students[i1]==students[i2]) printf("%d\n", students[i1]);
        }
    }

    return 0;
}