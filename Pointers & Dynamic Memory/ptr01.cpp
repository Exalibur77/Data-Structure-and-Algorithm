#include<iostream>
using namespace std;

// Address is stored as a hexadecimal value (base 16)
int main(){

    // gives the address of the variable x
    int x=5;
    cout << &x << endl;

    float y=3.5;
    cout << &y << endl;


    return 0;
}