#include<iostream>
#include<cstring>
using namespace std;

// Shallow and Deep copy of Objects of Class

class Person{

private:
    char grade;
public:
    int id;
    char *name;

    // default constructor
    Person(){
        cout << "Person class default constructor called " << endl; 
    }

    // parameterized constructor
    Person(char grade , int id , char name[]){
        this->name = new char[100];
        this->grade = grade;
        this->id = id; 
        strcpy(this->name,name);
    }

    // Inbuilt  constructor makes shallow copy of the current object.

    void setGrade(char ch){
        grade = ch;
    }

    void setId(int id){
        this->id = id;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }

    void getDetails(){
        cout << "[ ";
        cout << "Name: " << this->name << " ,";
        cout << "Grade => " << grade << " ,";
        cout << "Id => " << id << "  ]";
        cout << endl;

    }
};

int main(){

    char name[7] = "babbar";

    Person S('A',1,name);
    S.getDetails();

    // An inbuilt defined copy constructor is called to make a shallow copy of s in r.
    Person R(S);
    R.getDetails();


    // This copy is a shallow copy and each and evey thing is copied in another object so change in value at the same address make change in the original object.
    R.name[0] = 'G';
    R.getDetails();

    S.getDetails();

    return 0;
}