#include <stdio.h>

void showlist(int *list, int size){
    for(int i=0; i<size; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

int partition(int *list, int start, int end){
    int pivotpos = end-1;
    int helper;
    for(int i=start; i<end-1; i++){
        if(list[i]>=list[pivotpos]){
            //breaking
            if(i>=pivotpos) break;
            //debug
            printf("1(%d)- ", i);
            showlist(list, 32);
            //pivot goes one space to the back
            helper = list[pivotpos-1];
            list[pivotpos-1] = list[pivotpos];
            list[pivotpos] = helper;
            pivotpos--;
            //debug
            printf("2- ");
            showlist(list, 32);
            //breaking
            if(i>=pivotpos) break;
            //item switches spaces with element after pivot
            helper = list[pivotpos+1];
            list[pivotpos+1] = list[i];
            list[i] = helper;
            i--;
            //debug
            printf("3- ");
            showlist(list, 32);
            printf("\n");
        }
    }
    return pivotpos;
}

void quick(int *list, int start, int end){
    //debug
    printf("-- new quicksort instance: %d to %d\n", start, end);
    int pivot = partition(list, start, end);
    /*if(end-start>2){
        quick(list, pivot+1, end);
        quick(list, start, pivot);
    }*/
   if(pivot+1<end-1) quick(list, pivot+1, end);
   if(start<pivot-1) quick(list, start, pivot);
}

int main(){
    int list[] = {-7, 38, -27, 45, 1025, 714, 1, 2, 5, 3, 4, 4, 6, 7, 14, 900, -7, 38, -27, 45, 1025, 714, 1, 2, 5, 3, 4, 4, 6, 7, 14, 900};

    quick(list, 0, 32);    

    showlist(list, 32);
    return 0;
}