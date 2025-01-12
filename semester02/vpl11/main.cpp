#include <iostream>
#include <memory>
using namespace std;


class Teste{
    public:
        int attr;

        Teste(){
            this->attr = 0;
        }
        Teste(int value){
            this->attr = value;
            cout << "Construtor " << this->attr << endl;
        }

        ~Teste(){
            cout << "Destrutor " << this->attr << endl;
        }
};


int main(){
    int n; cin >> n;

    if(n%2==0){
        for(int c=1; c<=n; c++){
            Teste *test_pointer = new Teste(c);
            unique_ptr<Teste> test_unique_pointer(new Teste(c));
        }

    }
    else{
        shared_ptr<Teste> test_shared_pointer = make_shared<Teste>(0);
        for(int c=1; c<=n; c++){
            shared_ptr<Teste> new_test_shared_pointer = test_shared_pointer;
            new_test_shared_pointer->attr = c;
        }
        cout << test_shared_pointer.use_count() << endl;
    }
    return 0;
}