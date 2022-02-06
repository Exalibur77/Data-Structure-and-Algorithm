#include<iostream>
using namespace std;

// Copy Constructor

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

    // User defined copy constructor can also be made



    // now cannot pass temp as value ie. copy is made but since now original inbuilt is removed and new one is being formed but it is not completed yet so it makes problem.
    Person(Person &temp){
        cout << "Copy Constructor is called " << endl;
        this->grade = temp.grade;
        this->id = temp.id;

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


    Person S('A',1);
    S.getDetails();

    // An inbuilt defined copy constructor is called to make a copy of s in r.
    Person R(S);
    R.getDetails();

    return 0;
}