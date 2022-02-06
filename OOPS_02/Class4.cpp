#include<iostream>
using namespace std;

// Default and Parameterized constructor

class Person{
private:
    char grade;
public:
    int id;

    // default constructor
    Person(){
        cout << "Person class default constructor called " << endl; 
    }

    // parameterized constructor

    Person(char grade){
        cout << "Person class parameterized constructor called " << endl; 
        // if same paramter name and class object is there , then use this keyword to emphasize over grade of class
        this->grade = grade;

        // cout << "this -> " << this << endl;
    }

    /*
        This keyword is a pointer pointing to the current object of the class.
    */

    // Multiple parameterized constructor can be made.

    Person(char grade , int id){
        this->grade = grade;
        this->id = id; 
    }


    void setGrade(char ch){
        grade = ch;
    }

    void getGrade(){
        cout << "Grade => " << grade << endl;
    }

    void getDetails(){

        cout << "Grade => " << grade << endl;
        cout << "Id => " << id << endl;

    }
};

int main(){

    /*
        Whenever a object of a class is called an inbuilt default constructor.

        If we make our own default or either parameterized constructor it overwrites the inbuilt default constructor.
    */


    Person p1('A'); // now here default constructor is not called instead a parameterized constructor is called.
    p1.getDetails();

    // cout << "Address of object p1  " << &p1 << endl;

    Person *p2 = new Person('C');
    p2->getDetails();


    Person *p3 = new Person('B',100);
    p3->getDetails();

    return 0;
}