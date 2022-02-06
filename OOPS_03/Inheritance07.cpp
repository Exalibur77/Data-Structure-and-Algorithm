#include<iostream>
#include<string>
using namespace std;

/*
    Types of Inheritance 

    Hierarchical Inheritance 


                                     Parent Class 
                                        \     \
                                        \     \
                                    Child1  Child 2
                                
                    
*/


class Parent{

public:

    void func1(){
        cout << "Inside func1" << endl;
    }
};

class child1 : public Parent{

public:

    void func2(){
        cout << "Inside func2" << endl;
    }

};

class child2 : public Parent{

public:

    void func3(){
        cout << "Inside func3" << endl;
    }

};



int main(){

    Parent obj1;
    obj1.func1();

    child1 obj2;
    obj2.func1();
    obj2.func2();

    child2 obj3;
    obj3.func1();
    obj3.func3();


    return 0;
}