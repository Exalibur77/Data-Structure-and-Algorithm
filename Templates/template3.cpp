#include<iostream>
using namespace std;

// Use this template for using multiple parameters.
template <class T1, class T2 , class T3 = char> // same as default value in a function

// Function template
string join(T1 x , T2 y , T3 z){

    string temp;

    temp+=x;
    temp+=y;
    temp+=z;

    return temp;
}

int main(){

    cout << join <char,char,char> ('A','B','C') << endl;
    cout << join <char,int> ('A',97,100) << endl;
    cout << join<int,int> (97,98,100) << endl;

    return 0;
}