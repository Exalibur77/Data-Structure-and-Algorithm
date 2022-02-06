#include<iostream>
using namespace std;

class Person{
private:
    char grade;
public:
    int id;

    void setGrade(char ch){
        grade = ch;
    }

    void getGrade(){
        cout << "Grade => " << grade << endl;
    }

};

int main(){

    // static allocation of the object named sam
    Person sam;

    sam.id = 99;
    cout << sizeof(sam) << endl;
    sam.setGrade('A');
    cout << "Id ==> "  << sam.id << endl;
    sam.getGrade();


    // dynamically allocated object named garg
    Person *garg = new Person;

    // (*garg).id = 101; or
    garg->id = 101;
    cout << sizeof(*garg) << endl;
    (*garg).setGrade('B');
    cout << "Id ==> "  << garg->id << endl;
    (*garg).getGrade();





    return 0;
}