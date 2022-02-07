#include<iostream>
using namespace std;

class base{

    public:
    int var_base;

    virtual void print(){
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

    base * base_ptr;
    derived * derived_ptr;

    base obj_base;
    derived obj_derived;

    // Base class pointer is pointing to the derived class object.
    base_ptr = &obj_derived;

    base_ptr->var_base = 100;

    base_ptr->print(); // Here using the virtual function in the base class unables us to call the derived class function.
    // ie default behaviour is now changed.


    return 0;
}
/*

Rules:


1.They cannot be static
2. They are accessed by object pointers
3. Virtual functions can be a friend of another class
4. A virtual function in the base class might not be used.
5. If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class, if not redefined base class function will be called.




*/