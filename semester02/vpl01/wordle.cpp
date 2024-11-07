#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> readfile(){
    ifstream file;
    file.open("palavras.txt", ios::in);
    string line;
    vector<string> wordlist;
    int linecounter = 0;
    if(file.is_open()){
        while(getline(file, line)){
            if(linecounter!=0){
                wordlist.push_back(line);
            }
            linecounter++;
        }
    }
    return wordlist;
}


void main_game_loop(string chave){
    string absent_letters;
    string guess;
    bool perfect_guess;
    for(int i=0; i<5; i++){
        cin >> guess;
        perfect_guess = true;
        for(unsigned int letter=0; letter<chave.length(); letter++){
            if(guess[letter]==chave[letter]){
                guess[letter] = toupper(static_cast<unsigned char>(guess[letter]));
                cout << guess[letter];
            }
            else if(chave.find(guess[letter])!=string::npos){
                cout << guess[letter];
                perfect_guess = false;
            }
            else{
                cout << "*";
                if(absent_letters.find(guess[letter])!=string::npos){}
                else{
                    absent_letters+=guess[letter];
                }
                perfect_guess = false;
            }
        }
        transform(absent_letters.begin(), absent_letters.end(), absent_letters.begin(), ::toupper);
        cout << " (" << absent_letters << ")" << endl;
        if(perfect_guess){
            cout << "GANHOU!" << endl;
            return;
        }
    }
    cout << "PERDEU! " << chave << endl;
}


int main(){
    vector<string> wordlist = readfile();
    int key = 0; cin >> key;
    string key_word = wordlist[key-1];
    main_game_loop(key_word);
    return 0;
}