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
    string buffer;
    getline(cin, buffer);
    vector<string> words = split_string_by_spaces(buffer);
    for(int i=0; i<words.size(); i++){
        cout << words[i] << endl;
    } 
}