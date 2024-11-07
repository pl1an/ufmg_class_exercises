#include <iostream>
using namespace std;


// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por valor
//    - A segunda deve ser passada por referência 
//    - A terceira deve ser passada "por referência" usando apontadores (passagem "por referência" disponível em C)
//    A função deverá somar 1 ao valor de cada uma das 3 variáveis e retornar.
int func0(int a, int &b, int *c){
    a++;
    b++;
    (*c)++;
    return 0;
}


int main(){
    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int v1;
    cin >> v1; 
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *v2 = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int *v3 = nullptr;
    int v32;
    cin >> v32;
    v3 = new int[v32];
    for(int i=0; i<v32; i++){
        cin >> *(v3+i);
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &v1 << endl; 

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << v1 << endl; 

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &v2 << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << v2 << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &v3 << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &(v3[0]) << endl; 

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << v3[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    v2 = &v1; 

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << v2 << endl; 

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << (*v2) << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    (*v2) = 5; 

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << v1 << endl; 

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    v2 = v3; 

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << v2 << endl; 

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << (*v2) << endl; 

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    v2 = &(v3[0]); 

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    if(v2==v3) cout << "S" << endl;
    else cout << "N" << endl;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << v2 << endl; 

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << (*v2) << endl; 

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for(int i=0; i<v32; i++){
        *(v2+i) *= 10;
    } 

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for(int i=0; i<v32-1; i++){
        cout << v3[i] << " ";
    }
    cout << v3[v32-1] << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for(int i=0; i<v32-1; i++){
        cout << (*(v3+i)) << " ";
    } 
    cout << v3[v32-1] << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for(int i=0; i<v32-1; i++){
        cout << (*(v2+i)) << " ";
    } 
    cout << v3[v32-1] << endl;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    v2 = &(v3[v32-1]); 

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << v2 << endl; 

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << (*v2) << endl; 

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **v30 = &v2; 

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << v30 << endl; 

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &v30 << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << (*v30) << endl; 

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << (*(*v30)) << endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int v35, v352, v353;
    cin >> v35;
    cin >> v352;
    cin >> v353;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    func0(v35, v352, &v353);
    
    // 37) Imprima o valor das 3 variáveis criadas em (35)
    cout << v35 << " " << v352 << " " << v353;
    
    return 0;
}