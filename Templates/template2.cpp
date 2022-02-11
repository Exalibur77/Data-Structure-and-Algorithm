#include<iostream>
using namespace std;

// Function Template 
template <class T>
T maxi(T x, T y){

    return (x>y) ? x : y;

}

// Class Template
template <class T1 = char, class T2 = int>
class student{

    T1 a;
    T2 b;
    public:
    student(T1 a , T2 b) : a(a),b(b){}

    void print(){

        cout << "Value of a ->" << a << endl;
        cout << "Value of b ->" << b << endl;

    }


};


int main(){

    // cout << maxi<int>(23,9) << endl;
    // cout << maxi<float>(23.9,2.39) << endl;
    // cout << maxi<char> ('a','X') << endl;
    // cout << maxi<string> ("Xbc","Xya") << endl;

    // student <>obj(100,90);
    // obj.print();
    // student <int>obj1(100,90);
    // obj1.print();
    // student <char, char>obj2(65,97);
    // obj2.print();
    // student <float>obj3(65.98,97);
    // obj3.print();
    // student <float,char>obj4(65.98,97);
    // obj4.print();



}