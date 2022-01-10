#include<iostream>
#include<string>
using namespace std;

// Find , erase  and substr function of string. 

int main(){

    // 1. finds the index of the specified character or string
    // string s0="Today I am very happy.";
    // int indx1=s0.find('v');
    // int indx2=s0.find("pp");

    // cout << indx1 << endl;
    // cout << indx2 << endl;

// =================================================
    // 2. erase a specific part of the given string.

    // Syntax ==> s.erase(index,number of elements)

    // string str="Today I am very happy.";
    // str.erase(2,5);// erases 5 elements from index 2
    // str.erase(3); //erases all the indexx from the index 3

    // cout << str << endl;

// =================================================

    // 3. Accessing substring of the given string

    // Syntax ==> s.substr(index,number of elements)

    // string str="Today I am very happy.";

    // string sub_string=str.substr(10,2);

    // cout << sub_string << endl;


    return 0;
}