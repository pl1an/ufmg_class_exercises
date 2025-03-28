#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class NegativeResultException : public exception {
public:
    int value;
    NegativeResultException(int value){
        this->value = value;
    }
    const char* what() const noexcept override{
        return "Erro: Resultado Negativo.";
    }
};

int main() {
    vector<int> arr = {-20, -10, 0, 10, 20};
    try {
        int choosen_position = 0;
        cin >> choosen_position;
        //invalid position
        if(choosen_position<0||choosen_position>=static_cast<int>(arr.size())) throw out_of_range("Erro: Parametro invalido");
        int choice = arr.at(choosen_position);
        //negative number choosen
        if (choice<0) throw NegativeResultException(choice);
        //0 choosen
        if (choice==0) throw logic_error("Erro: O resultado não deve ser zero");
        cout << choice << endl;
    } catch (const NegativeResultException& e) {
        cout << e.what() << endl;
        cout << e.value << endl;
    } catch (const exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}