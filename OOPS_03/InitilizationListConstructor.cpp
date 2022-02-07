#include<iostream>
using namespace std;

class X{

    int y,x;

    public:


    // X(int a, int b): x(a),y(b)
    // X(int a, int b): x(a),y(a+b)
    // X(int a, int b): x(b),y(x+a)
    // X(int a, int b): y(b),x(a)

    // X(int a, int b): y(b),x(y+a) // This gives unexpected results as x is initilzed before y. and x = y+a as y is not defined till now in class.
    // It will work if we declare y before x in class.


    X(int a, int b): x(a),y(b){
        cout << "Constructor is called . " << x << " " << y << endl; 
    }

};


int main(){

    X obj(23,1);


    return 0;
}