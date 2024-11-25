#include "aluno.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


aluno::aluno(string nome, int matricula, vector<int> notas){
    this->nome = nome;
    this->matricula = matricula;
    this->notas = notas;
}

int aluno::menor_nota(){
    int menor = this->notas[0];
    if(this->notas.empty()) return 0;
    for(int nota : this->notas){
        if(nota<menor){
            menor=nota;
        }
    }
    return menor;
}

int aluno::maior_nota(){
    int maior = this->notas[0];
    if(this->notas.empty()) return 0;
    for(int nota : this->notas){
        if(nota>maior){
            maior = nota;
        }
    }
    return maior;
}

float aluno::calcular_media(){
    float sum = 0;
    if(this->notas.empty()) return 0;
    for(int nota : this->notas){
        sum += nota;
    }
    return sum/notas.size();
}

void aluno::show_self(){
    cout << this->matricula << " " << this->nome << " "; 
    for(int nota : this->notas){
        cout << nota << " ";
    }
    cout << endl;
    cout << fixed << setprecision(2) << this->calcular_media() << " " << this->maior_nota() << " " << this->menor_nota() << endl;
}