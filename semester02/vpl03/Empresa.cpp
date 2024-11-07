#include <string>
#include <vector>
#include <iostream>

#include "Empresa.hpp"
#include "Onibus.hpp"

using namespace std;

Empresa::Empresa(){
    numero_de_veiculos_cadastrados = 0;
    veiculos_cadastrados = {};
}

Onibus* Empresa::adicionar_onibus(string placa, int max_passageiros) {
    Onibus* new_bus;
    for(unsigned int i=0; i<veiculos_cadastrados.size(); i++){
        if((*(veiculos_cadastrados[i])).placa == placa){
            return nullptr;
        }
    }
    new_bus = new Onibus(placa, max_passageiros);
    veiculos_cadastrados.push_back(new_bus);
    return new_bus;
}

Onibus* Empresa::busca_onibus(string target_placa) {
    for(unsigned int i=0; i<veiculos_cadastrados.size(); i++){
        if((*(veiculos_cadastrados[i])).placa == target_placa){
            return veiculos_cadastrados[i];
        }
    }
    return nullptr;
}

void Empresa::transferir_entre_veiculos(string placa_origin, string placa_target, int passageiros_transferidos){
    Onibus* origin_bus = this->busca_onibus(placa_origin);
    Onibus* target_bus = this->busca_onibus(placa_target);
    if(origin_bus==nullptr || target_bus==nullptr) cout << "ERRO : onibus inexistente" << endl;
    else if(!(*origin_bus).transferir_passageiros(target_bus, passageiros_transferidos)) cout << "ERRO : transferencia cancelada" << endl;
    else cout << "transferencia de passageiros efetuada" << endl;

}

void Empresa::imprimir_estado() {
    for(unsigned int i=0; i<veiculos_cadastrados.size(); i++){
        (*(veiculos_cadastrados[i])).imprimir_estado();
    }
}