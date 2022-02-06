#include<iostream>
using namespace std;

// Default and Parameterized constructor

class Person{
private:
    char grade;
public:
    int id;

    Person(){
        cout << "Person class constructor called " << endl; 
    }


    void setGrade(char ch){
        grade = ch;
    }

    void getGrade(){
        cout << "Grade => " << grade << endl;
    }
};

int main(){

    /*
        Whenever a object of a class is called an inbuilt default constructor.

        If we make our own default constructor it overwrites the inbuilt default constructor.
    */


    // static allocation 
    Person sam;

    // sam.id = 99;
    // cout << sizeof(sam) << endl;
    // sam.setGrade('A');
    // cout << "Id ==> "  << sam.id << endl;
    // sam.getGrade();


    // dynamically allocated object named garg
    Person *garg = new Person;

    // (*garg).id = 101; or
    // garg->id = 101;
    // cout << sizeof(*garg) << endl;
    // (*garg).setGrade('B');
    // cout << "Id ==> "  << garg->id << endl;
    // (*garg).getGrade();





    return 0;
}