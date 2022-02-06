#include<iostream>
#include<string>
using namespace std;


/* Run Time PolyMorphism


    1. Function Overriding which is achieved by only using inheritance.


*/

class A{

    public:

    void func(){
        cout << "In A" << endl;
    }


};

class B : public A{

    public:

    void func(){

        cout << "In B" << endl;
    }


};

int main(){

    B obj;

    // func of B overrides the parent class func
    obj.func();

    // This polymorphism is used when some code we wanr to reuse and some we have to redefine for a particulaar child class seperately.

    return 0;
}