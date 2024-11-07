#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <vector>
#include "Onibus.hpp"

class Empresa {
    public:
        Empresa();

        vector<Onibus*> veiculos_cadastrados;
        int numero_de_veiculos_cadastrados;

        Onibus* adicionar_onibus(string placa, int max_passageiros);
        Onibus* busca_onibus(string target_placa);

        void transferir_entre_veiculos(string placa_origin, string placa_target, int passageiros_transferidos);

        void imprimir_estado();
};

#endif