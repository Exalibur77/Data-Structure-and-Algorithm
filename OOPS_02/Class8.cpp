#include<iostream>
#include<cstring>
using namespace std;

// Static Data Variable and Static functions

class Person{

private:
    char grade;
public:
    int id;
    char *name = new char[100];
    static int life;

    // default constructor
    Person(){
        cout << "Person class default constructor called " << endl; 
    }

    // parameterized constructor
    Person(char grade , int id , char name[]){
        
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
        // Freeing up the name memory that we have extra allocated to ensure the deep copy.
        cout << "Destructor is called " << name << endl;
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

    // Static function can only have access to static data member and does not have this keyword associated with it.
    
    static int random();
    // {
    //    life++;
    //    return life;
    // }

};

// Always static variable are initilized outside the class

int Person ::life = 3;


int Person::random(){
    life++;
    return life;
}


int main(){

    // There is no need to intilize an object to call static varible or function as it is not associated with any object rather than class.

    cout << Person :: life << endl;
    cout << Person ::random() << endl;


    // // This is not recommended.
    // Person p1;
    // cout << p1.life << endl;

    // Person p2;
    // p2.life = 5;

    // cout << p2.life << endl;
    // cout << p1.life << endl; // since it is static so also changes the value of life for whole class.


    return 0;
}