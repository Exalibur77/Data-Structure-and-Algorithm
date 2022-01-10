#include<iostream>
using namespace std;

// Pointer is a variable that stores the address of other variable
int main(){

    int x=5;
    
    int * x_ptr=&x;

    cout << "Address of x => "<< x_ptr << " " << &x << endl;
    cout << "Address of x_ptr => "<< &x_ptr << endl;

    // Pointer to pointer

    int ** x_x_ptr= &x_ptr;

    cout << "Address of x_ptr => "<< &x_ptr << " " << x_x_ptr << endl;
    cout << "Address of x_x_ptr =>" << &x_x_ptr << endl;

    return 0;
}