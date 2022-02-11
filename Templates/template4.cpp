#include<iostream>
using namespace std;

// Class Template
template <class T>
class student{

    T a;
    public:
    student(T a) : a(a){}

    void print();

};

// For outside decleration of the function

template <class T>
void student<T> :: print(){

    cout << "Value of a ->" << a << endl;
}

int main(){

    student <int>st(100);
    st.print();
    student <char>st1(100);
    st1.print();

    return 0;
}