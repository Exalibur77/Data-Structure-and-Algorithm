#include<iostream>
#include<string>
using namespace std;

// Parent Class
class Human{

    private:
    int age;

    
    protected:
    int weight;

    void setAge(int age){
        this->age = age;
    }

    public:
    int height;

    
    void setHeight(int h){
        height =h;
    }

    int getHeight(){
        return height;
    }

    int getAge(){
        return age;
    }

}; 

// Child Class

class Male : protected Human{

public:

    string color;

    void func(){
        cout << "Male Sleeping" << endl;
    }

    void setAgeMale(int age){
        setAge(age);

        cout << "age is :" << getAge() << endl;
    }


};

int main(){

    Male obj;

    // Gives error as Male is inherited protectedly and we cant access the public member of base class which is now acting as protected outside the child class

    // obj.height=10;

    // It is also unaccessible
    // obj.setHeight(10);


    obj.setAgeMale(100); // used to set age of Human class which is private usinf getter and setter of it which are inherited in my child class protectedly.

   

    return 0;
}