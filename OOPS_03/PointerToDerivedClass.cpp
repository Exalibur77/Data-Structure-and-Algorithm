#include<iostream>
using namespace std;

// Poly Morphism -- achieved using the pointer of base class to derived class.

class base{

    public:
    int var_base;

    void print(){
        cout << "Base Class Print Called , var_base -> " << var_base << endl;
    }


};

class derived : public base{

    public:
    int var_derived;

    void print(){
        cout << "Base Class Print Called , var_base -> " << var_base << endl;
        cout << "Derived Class Print Called , var_derived -> " << var_derived << endl;

    }


};

int main(){


    // derived obj1;
    // obj1.var_base=100;
    // obj1.var_derived=500;

    // obj1.print(); // derived class print is called because at run time , function print is got overrided.


    base * base_ptr;
    derived * derived_ptr;

    base obj_base;
    derived obj_derived;

    // Base class pointer is pointing to the derived class object.
    base_ptr = &obj_derived;

    base_ptr->var_base = 100;
    base_ptr->print(); // Here print of base class is called since pointer is of base class.


    // Derived class pointer pointing to derived class
    derived_ptr = &obj_derived;

    derived_ptr->var_base=200;
    derived_ptr->var_derived=198;
    derived_ptr->print(); // here print of derived class is invoked since pointer is of derived class.


    // // Cannot convert the base class object to a derived class pointer.
    // derived_ptr = &obj_base;



    return 0;
}