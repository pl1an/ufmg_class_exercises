#include <iostream>
#include "vetor.hpp"

using namespace std;

int main(){
    Vetor<char> arr(10);
    for(int i=93; i<103; i++){
        arr.AdicionaElemento(i);
    }
    arr.SetElemento(0, 'h');
    arr.Imprime();
    Vetor arr2(arr);
    Vetor<char> arr3 = arr2;
    arr2.Imprime();
    arr3.Imprime();
    return 0;
}