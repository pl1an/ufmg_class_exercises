#ifndef ONIBUS_H
#define ONIBUS_H

#include <string>
using namespace std;

class Onibus {
    
    public:
        Onibus(string placa, int max_passageiros);

        int max_passageiros;
        int passageiros;
        string placa;

        bool subir_passageiros(int passageiros_adicionados);
        bool descer_passageiros(int passageiros_removidos);
        bool transferir_passageiros(Onibus* onibus_alvo, int passageiros_transferidos);

        void imprimir_estado();
};

#endif