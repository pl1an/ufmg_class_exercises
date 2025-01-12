#include "heapint.hpp"
#include <iostream>

using namespace std;


HeapInt::HeapInt(){
    this->heapint = new int(0);
}
HeapInt::HeapInt(int target_int){
    this->heapint = new int(target_int);
}
HeapInt::HeapInt(const HeapInt &target_heapint){
    this->heapint = new int(*target_heapint.heapint);
}

HeapInt::~HeapInt(){
    delete this->heapint;
}

HeapInt &HeapInt::operator=(const int target_int){
    *(this->heapint) = target_int;
    return *this;
}
HeapInt &HeapInt::operator=(const HeapInt& target_heapint) {
    if (this != &target_heapint) {
        if (!this->heapint) {
            this->heapint = new int;
        }
        *(this->heapint) = *(target_heapint.heapint);
    }
    return *this;
}

HeapInt HeapInt::operator+(const int target_int) const{
    return HeapInt(*(this->heapint)+target_int);
}
HeapInt HeapInt::operator+(const HeapInt& target_heapint) const{
    return HeapInt(*(this->heapint)+*(target_heapint.heapint));
}
HeapInt HeapInt::operator-(const int target_int) const{
    return HeapInt(*(this->heapint)-target_int);
}
HeapInt HeapInt::operator-(const HeapInt& target_heapint) const{
    return HeapInt(*(this->heapint)-*(target_heapint.heapint));
}

bool HeapInt::operator==(const HeapInt& target_heapint) const{
    return *(this->heapint)==*(target_heapint.heapint);
}

ostream& operator<<(ostream& os, const HeapInt& target_heapint){
    os << *(target_heapint.heapint);
    return os;
}
istream& operator>>(istream& is, HeapInt& target_heapint) {
    if (!target_heapint.heapint) {
        target_heapint.heapint = new int;
    }
    is >> *target_heapint.heapint;
    return is;
}