#include<iostream>
#include<cstring>
using namespace std;

// Shallow and Deep copy of Objects of Class

class Person{

private:
    char grade;
public:
    int id;
    char *name ;

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


    // Making a user defined copy constructor to make a deep copy.

    Person(Person &temp){

        this->id = temp.id;
        this->grade = temp.grade;

        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);

        this->name = ch;

    }

    // Destructor is automatically only called for statically allocated objects. 

    // destructor 
    ~Person(){
        cout << "Destructor is called " << name << endl;
        // Freeing up the name memory that we have extra allocated to ensure the deep copy.
        delete []name;
    }

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

    // An userdefined  copy constructor is called to make a deep copy of s in r.
    Person R(S);
    R.getDetails();


    // This copy is a deep copy so change in name in R would not affect the S. 
    R.name[0] = 'G';
    R.getDetails();

    S.getDetails();

    // For this object we have to manually call the destructor by deleting the object.
    Person *Q = new Person();
    delete Q;



    return 0;
}