#include<iostream>
#include<string>
using namespace std;

/*
    Types of Inheritance 

    MultiLevel Inheritance 


                            Parent class
                                \
                                \
                            Child Class
                                \
                                \
                                \
                            Another Child Clas

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

    protected:
        string name;

};

class Breed : public Dog{

    public:
    void setName(string x){
        name = x;
    }

    string getName(){
        return name;
    }

};


int main(){

    Breed d;

    d.age=10;
    d.weight=1000;
    
    d.setName("Bella");
    
    d.speak();

    cout << d.age << endl;
    cout << d.weight << endl;

    cout << d.getName() << endl;


    return 0;
}