#include<iostream>
using namespace std;

// Constructor in Derived Class

class base1{
    private:
    int num;

    public:
    base1(int num):num(num){
        cout << "Base class 1 constructor is called." << endl;
    }

    void print1(){
        cout << num << endl;
    }

};

class base2{
    private:
    int num;

    public:
    base2(int num):num(num){
        cout << "Base class 2 constructor is called." << endl;
    }

    void print2(){
        cout << num << endl;
    }

};


// // This defines the order of constructor called of base class
// class derived : public base2,public base1{
//     int val;
//     public:
//     // This does not define the order of constructor 
//     derived(int a,int b,int c):base2(a),base1(c),val(a){
//         // This is called as intilization list for the constructor of the base class.
//         cout << "Derived Class Constructor is called." << endl;
//     }

//     void printVal(){
//         cout << val << endl;
//     }

// };


// here virtual base class is given more preference than anyone. So base class 1 is called first
class derived : public base2,virtual public base1{
    int val;
    public:
    // This does not define the order of constructor 
    derived(int a,int b,int c):base2(a),base1(c),val(a){
        // This is called as intilization list for the constructor of the base class.
        cout << "Derived Class Constructor is called." << endl;
    }

    void printVal(){
        cout << val << endl;
    }

};




int main(){


    derived obj(23,5,10);
    obj.print1();
    obj.print2();   
    obj.printVal();

    return 0;
}