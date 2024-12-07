#include <iostream>
#include <list>
#include <string>
using namespace std;


class MainClass{
    private:
        static int automatic_instance_id;
        static int instance_count;

        int id;

    public:
        MainClass(){
            this->id = automatic_instance_id;
            automatic_instance_id++;
            instance_count++;
        }
        MainClass(int object_number){
            if(object_number<0){
                this->id = object_number;
                instance_count++;
            }
        }

        int return_instance_id(){
            return id;
        }
        MainClass* return_instance_addres(){
            return this;
        }
        static int return_instance_count(){
            return instance_count;
        }

        ~MainClass(){
            instance_count--;
        }

};

int MainClass::automatic_instance_id = 0;
int MainClass::instance_count = 0;


int main(){
    list<MainClass> main_list;
    MainClass new_instance;
    string buffer;

    while(true){
        cin >> buffer;
        // following A command
        if(buffer == "A"){
            new_instance = MainClass();
            main_list.push_back(new_instance);
            cout << new_instance.return_instance_id() << " " << new_instance.return_instance_addres() << endl;
        }
        // following C command
        if(buffer == "C"){
            cin >> buffer;
            if(stoi(buffer)<0){
                new_instance = MainClass(stoi(buffer));
                main_list.push_front(new_instance);
                cout << new_instance.return_instance_id() << " " << new_instance.return_instance_addres() << endl;
            }
            else{
                cout << "ERRO" << endl;
            }
        }
        // following R command
        if(buffer == "R"){
            if(main_list.empty()){
                cout << "ERRO" << endl;
            }
            else{
                cout << main_list.front().return_instance_id() << " " << main_list.front().return_instance_addres() << endl;
                main_list.pop_front();
            }
        }
        // following N command
        if(buffer == "N"){
            cout << main_list.size() << endl;
        }
        // following P command
        if(buffer == "P"){
            cin >> buffer;
            if(stoi(buffer)<1 || stoi(buffer)>(int)main_list.size()){
                cout << "ERRO" << endl;
            }
            else{
                auto it = main_list.begin();
                advance(it, stoi(buffer)-1);
                cout << (*it).return_instance_id() << " " << (*it).return_instance_addres() << endl;
            }
        }
        // following L command
        if(buffer == "L"){
            auto it = main_list.begin();
            while(it!=main_list.end()){
                cout << (*it).return_instance_id() << " " << (*it).return_instance_addres() << endl;
                it++;
            }
        }
        // following E command (break)
        if(buffer == "E"){
            main_list.clear();
            break;
        }
    }
}