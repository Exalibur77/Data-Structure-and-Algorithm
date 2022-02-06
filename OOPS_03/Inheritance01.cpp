#include<iostream>
#include<string>
using namespace std;

// Parent Class
class Human{

    private:
    int age; // age is not accessible anywhere in derived class 

    public:
    int height;

    protected:
    int weight;

    public:
    void setAge(int age){
        this->age = age;
    }

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

class Male : public Human{

    // weight inherited is protected only right now so we can access it in mainbut can acess in Male
    public:

        string color;
        
        void setWeight(int h){
            weight =h;
            weight++;
        }

        void func(){
            cout << "Male Sleeping" << endl;
        }

        
    

};

int main(){

    Male obj;

    obj.setWeight(100);

    cout << obj.weight << endl; // Inaccesible as weight is protected member and we cannot access it out of the derived or child class.


    // obj.setHeight(10);

    // cout << obj.getHeight() << endl;

    // obj.color ="red";

    // cout << obj.color << endl;

    // obj.func();


    return 0;
}