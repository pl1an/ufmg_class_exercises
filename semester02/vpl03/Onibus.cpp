#include <iostream>
#include <string>
#include "Onibus.hpp"

Onibus::Onibus(string placa, int max_passageiros) {
    this->placa = placa;
    this->max_passageiros = max_passageiros;
    this->passageiros = 0;
}

bool Onibus::subir_passageiros(int passageiros_adicionados) {
    if(passageiros+passageiros_adicionados>max_passageiros) return false;
    passageiros += passageiros_adicionados;
    return true;
}

bool Onibus::descer_passageiros(int passageiros_removidos) {
    if(passageiros-passageiros_removidos<0) return false;
    passageiros -= passageiros_removidos;
    return true;
}

bool Onibus::transferir_passageiros(Onibus* onibus_alvo, int passageiros_transferidos) {
    if(this->descer_passageiros(passageiros_transferidos) && (*onibus_alvo).subir_passageiros(passageiros_transferidos)){
        return true;
    }
    else{
        return false;
    }
}

void Onibus::imprimir_estado() {
    cout << placa << " " << "(" << passageiros << "/" << max_passageiros << ")" << endl;
}