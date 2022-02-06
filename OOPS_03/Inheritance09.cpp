#include<iostream>
using namespace std;

// Inheritance Ambiguity

class A{

    public:
    void func(){
        cout << "Func A is called" << endl;
    }

};

class B{

    public:
    void func(){
        cout << "Func B is called" << endl;
    }

};

// Here multiple inheritance have been implemented.
class C: public A, public B{

};


int main(){

    C obj;

    obj.B::func();
    obj.A::func();



    return 0;
}