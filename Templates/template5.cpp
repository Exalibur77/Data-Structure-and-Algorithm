#include<iostream>
using namespace std;

// Template Function Overloading

void func(int a){
    cout << "First function " <<a  << endl;
}

template <class T>
void func(T a){
    cout << "I am templatized func " << a << endl;
}

int main(){

    func('A');
    func(10.4);
    func(2); // Exact math function takes higher priority
    return 0;
}