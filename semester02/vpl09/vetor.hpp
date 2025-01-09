#ifndef UNIFIEDVECTOR
#define UNIFIEDVECTOR

#include <iostream>

using namespace std;

template <typename GenericArrayElement>

class Vetor{
    private:

        GenericArrayElement* generic_array;
        int size;
        int last_free_position;

    public:

        Vetor(int n){
            this->generic_array = new GenericArrayElement[n];
            this->size = n;
            this->last_free_position = 0;
        }
        Vetor(const Vetor& target){
            this->generic_array = new GenericArrayElement[target.size];
            this->size = target.size;
            this->last_free_position = 0;
            for(int i=0; i<target.size; i++){
                this->generic_array[i] = target.generic_array[i];
            }
            this->last_free_position = this->size;
        }
        ~Vetor(){
            delete[] generic_array;
        }

        void SetElemento(int i, GenericArrayElement element){
            this->generic_array[i] = element;
        }
        GenericArrayElement GetElemento(int i){
            return this->generic_array[i];
        }
        void AdicionaElemento(GenericArrayElement element){
            this->generic_array[last_free_position] = element;
            this->last_free_position += 1;
        }

        void Imprime(){
            for(int i=0; i<this->size; i++){
                if(i==this->size-1) cout << this->generic_array[i] << endl;
                else cout << this->generic_array[i] << " ";
            }
        }
};

#endif