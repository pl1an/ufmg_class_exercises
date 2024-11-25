#ifndef ALUNO
#define ALUNO

#include <string>
#include <vector>

using namespace std;

class aluno{
    string nome;
    int matricula;
    vector<int> notas;

    void aluno(string nome, int matricula, vector<int> notas);

    int menor_nota();
    int maior_nota();
    float calcular_media();
    void show_self();
}

#endif