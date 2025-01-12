#include "heapint.cpp"
#include <iostream>

using namespace std;

int main(){
    HeapInt a, b, c;
    cin >> c >> a >> b;
    c = b;
    cout << "a: " << a << "/b: " << b << "/c:" << c << endl;
    cout << a-b <<" " << a-c << " " << a+b << " " << a+c << endl;
    c = a+b;
    cout << " " << c << " " << c-b;
    cout << endl << a << ":" << b << ":" << c << endl;
    cout << a+10 << " " << a-10;
    return 0;
}