#include "aluno.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool sort_function(aluno a1, aluno a2){
    vector<string> temp_array;
    temp_array.push_back(a1.nome);
    temp_array.push_back(a2.nome);
    sort(temp_array.begin(), temp_array.end());
    if(temp_array[0] == a1.nome) return true;
    else return false;
}


int main(){
    vector<aluno> alunos; 

    int loop1 = true;
    int loop2 = true;

    string name_buffer;
    int matricula_buffer;
    int nota_buffer;
    vector<int> notas_buffer;

    while(loop1){
        cin >> name_buffer;
        if (name_buffer == "END") loop1 = false;
        else{
            cin >> matricula_buffer;
            loop2 = true;
            while(loop2){
                cin >> nota_buffer;
                if(nota_buffer == -1) loop2 = false;
                else{
                    notas_buffer.push_back(nota_buffer);
                }
            }
            aluno aluno_buffer = aluno(name_buffer, matricula_buffer, notas_buffer);
            alunos.push_back(aluno_buffer);
            notas_buffer.clear();
        }
    }

    sort(alunos.begin(), alunos.end(), sort_function);
    for(unsigned int i=0; i<alunos.size(); i++){
        alunos[i].show_self();
    }

    return 0;
}