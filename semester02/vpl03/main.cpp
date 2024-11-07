#include <iostream>
#include <string>
#include <sstream>

#include "Empresa.hpp"
#include "Onibus.hpp"

using namespace std;

vector<string> split_string_by_spaces(string target_string) {
    stringstream stream(target_string);
    vector<string> words;
    string word;
    while(stream>>word){
        words.push_back(word);
    }
    return words;
}

int main() {
    Empresa main_empresa = Empresa();
    string buffer = "";
    vector<string> split_buffer = {""};

    while(buffer[0] != 'F'){
        getline(cin, buffer);
        if(buffer!="") split_buffer = split_string_by_spaces(buffer);

        if(split_buffer[0] == "I"){
           main_empresa.imprimir_estado(); 
        }
        if(split_buffer[0] == "C"){
            Onibus* added_bus = main_empresa.adicionar_onibus(split_buffer[1], stoi(split_buffer[2]));
            if(added_bus==nullptr) cout << "ERRO : onibus repetido" << endl;
            else cout << "novo onibus cadastrado" << endl;
        }
        if(split_buffer[0] == "S"){
            Onibus* target_bus = main_empresa.busca_onibus(split_buffer[1]);
            if(target_bus==nullptr) cout << "ERRO : onibus inexistente" << endl;
            else if(!(*target_bus).subir_passageiros(stoi(split_buffer[2]))) cout << "ERRO : onibus lotado" << endl;
            else cout << "passageiros subiram com sucesso" << endl;
        }
        if(split_buffer[0] == "D"){
            Onibus* target_bus = main_empresa.busca_onibus(split_buffer[1]);
            if(target_bus==nullptr) cout << "ERRO : onibus inexistente" << endl;
            else if(!(*target_bus).descer_passageiros(stoi(split_buffer[2]))) cout << "ERRO : faltam passageiros" << endl;
            else cout << "passageiros desceram com sucesso" << endl;
        }
        if(split_buffer[0] == "T"){
            main_empresa.transferir_entre_veiculos(split_buffer[1], split_buffer[2], stoi(split_buffer[3])); 
        }
    }

    return 0;
}