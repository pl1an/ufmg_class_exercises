#include <stdio.h>

int main(){
    int finboacci[802] = {0, 1};
    int target=0;
    for(int i=2; i<801; i++){
        finboacci[i]=finboacci[i-1]+finboacci[i-2];
    }

    while(target>=0 && target<801){
        scanf("%d", &target);
        printf("%d\n", finboacci[target]);
    }

    return 0;
}