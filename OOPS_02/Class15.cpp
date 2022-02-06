#include<iostream>
using namespace std;

// More on friend function.

class Y;

class X{
    int data;

    friend void SwapVal(X&,Y&);

public:
    X(int data):data(data){}

    void getData(){
        cout << " Data of X => " << data << endl; 
    }

};


class Y{
    int data;
    friend void SwapVal(X&,Y&);

public:
    Y(int data):data(data){}

    void getData(){
        cout << " Data of Y=> " << data << endl; 
    }

};

// Making a function that uses the data of X and Y class and Add them up

void SwapVal(X &o1 , Y &o2){
    
    int temp=o1.data;
    o1.data = o2.data;
    o2.data = temp; 

}


int main(){

    X a(1);
    Y b(110);

    a.getData();
    b.getData();

    SwapVal(a,b);

    a.getData();
    b.getData();

    return 0;
}