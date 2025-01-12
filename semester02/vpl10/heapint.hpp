#ifndef HEAPINT
#define HEAPINT

#include <iostream>
using namespace std;

class HeapInt{
    public:
        int *heapint;

        HeapInt();
        HeapInt(int value);
        HeapInt(const HeapInt &target_heapint);
        ~HeapInt();

        HeapInt& operator=(const int target_int);
        HeapInt& operator=(const HeapInt& target_heapint);
        bool operator==(const HeapInt& target_heapint) const;
        
        HeapInt operator+(const int target_int) const;
        HeapInt operator+(const HeapInt& target_heapint) const;
        HeapInt operator-(const int target_int) const;
        HeapInt operator-(const HeapInt& target_heapint) const;
        
        friend ostream& operator<<(ostream& os, const HeapInt& target_heapint);
        friend istream& operator>>(istream& os, HeapInt& target_heapint);
};

#endif