#include<iostream>
#include<string>
using namespace std;


/* Compile Time PolyMorphism


    1. Function Overloading

    2. Operator Overloading


*/


class A{

    
    public:
        int a,b;

        // Function Overloading 

        void func(){
            cout << "Hello Sanskar ..!" << endl;
        }

        void func(string name){
            cout << "Hello " << name << " ..!" << endl;
        }


        // Operator Overloading

        void operator+ (){
            // + operator is overloaded to substract.
            cout << abs(a-b) << endl;
        }

};


int main(){

    A obj;

    obj.func();

    obj.func("Bella");

    obj.a=1;
    obj.b=10;

    +obj;

    return 0;
}