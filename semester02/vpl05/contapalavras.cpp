#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

struct word_type{
    string word;
    int quantity = 1;
};
bool compare_function(word_type i, word_type j){
    return i.word < j.word;
}

int main(){
    vector<word_type> words;
    string word;

    string filename;
    cin >> filename;
    ifstream f(filename);
    stringstream buffer;

    while(f >> word){
        for(unsigned int i=0; i<word.length(); i++){
            if(!isalnum(word[i])){
                word[i] = ' ';
            }
            word[i] = tolower(word[i]);
        }
        buffer << word;
        if(word[word.length()-1]!=' ') buffer << " ";
    }

    bool already_known_word = false;
    word_type pushword;
    while(buffer >> word){
        already_known_word = false;
        for(unsigned int i=0; i<words.size(); i++){
            if(words[i].word==word){
                already_known_word = true;
                words[i].quantity++;
            }
        }
        if(!already_known_word){
            pushword.word = word;
            words.push_back(pushword);
        }
    }

    sort(words.begin(), words.end(), compare_function);
    for(unsigned int i=0; i<words.size(); i++){
        cout << words[i].word << " " << words[i].quantity << endl;
    }
    
    return 0;
}