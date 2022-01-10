#include<iostream>
using namespace std;


int main(){

    int x=5;
    int * ptr= &x;

    // Address of x
    cout << ptr << " " << &x << endl;

    // value at x using dereference operator
    cout << x << " " << *ptr << endl;

    return 0;
}