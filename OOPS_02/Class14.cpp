#include<iostream>
using namespace std;

// More on friend function.

class Y;

class X{
    int data;

    friend int Add(X,Y);

public:
    X(int data):data(data){}

};


class Y{
    int data;
    friend int Add(X,Y);

public:
    Y(int data):data(data){}

};

// Making a function that uses the data of X and Y class and Add them up

int Add(X o1 , Y o2){
    return o1.data + o2.data;
}


int main(){

    X a(1);
    Y b(110);

    cout << Add(a,b) << endl;
    return 0;
}