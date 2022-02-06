#include<iostream>
using namespace std;

// Copy Constructor and Copy Assignment Operator

class Person{

    public:
    int x,y;
    Person(int x , int y){

        this->x = x;
        this->y = y;

    }

    void PrintAdd(){
        cout << &x << endl;
        cout << &y << endl;
    }

    // Making a user defined copy assignment operator function

    Person& operator = (const Person &temp){
        // This is a shallow copy it would work fine and same as inbuilt copy assignment operator.

        // This get change when dynamically allocated data members are there then we need to make our own copy assignment operator.{same changes that we make in copy constructor.}

        this->x = temp.x;
        this->y = temp.y;

        return *this; // return the current Person object 

    }


    void getDetails(){
        cout << x << endl;
        cout << y << endl;
        cout << "============" << endl;
    }

};

int main(){


    Person p1(12,43);

    Person p2(1,2);


    p1.getDetails();
    p2.getDetails();

    // Now copy assignment operator is called which by default makes a shallow copy.

    p1.operator=(p2); // both same 
    // p1 = p2;

    p1.getDetails();
    p2.getDetails();



    // Person p1(2,4);

    // p1.PrintAdd();
    // p1.getDetails();

    // // Inbuilt copy constructor is called.
    // Person p2(p1);
    // p2.x=100;
    // p2.PrintAdd();
    // p2.getDetails();


    // p1.PrintAdd();
    // p1.getDetails();
}