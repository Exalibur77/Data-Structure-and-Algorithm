#include<iostream>
#include<string>
using namespace std;

/*
    Types of Inheritance 

    Multiple  Inheritance 


                            Parent1   and   Parent2 
                                        \
                                        \
                                    Child Class
                                
                        

*/


class Animal{

public:
    int weight;
    int age;

    void bark(){
        cout << "Barking" << endl;
    }
};

class Human{

public:
    string color;

    void speak(){
        cout << "Speaking" << endl;
    }

};

class mix : public Animal,public Human{


};


int main(){

    mix d;

    d.age=10;
    d.weight=1000;
    
    d.color="black";
    
    d.speak();
    d.bark();

    cout << d.age << endl;
    cout << d.weight << endl;
    cout << d.color << endl;


    return 0;
}