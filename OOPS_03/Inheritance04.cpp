#include<iostream>
using namespace std;

/*
    Types of Inheritance 

    Single Inheritance 


                            Parent class
                                \
                                \
                            Child Class

*/


class Animal{

public:
    int weight;
    int age;

    void speak(){
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal{


};



int main(){

    Dog d;

    d.age=10;
    d.weight=1000;

    d.speak();

    cout << d.age << endl;
    cout << d.weight << endl;



    return 0;
}