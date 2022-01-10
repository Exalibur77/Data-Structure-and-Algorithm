#include<iostream>
#include<string>
using namespace std;
// Append Function of strings
int main(){

    string s1="HELLO";
    string s2=" Guys how are you ?";

    // Syntax == > s1.append(s2,initial_index,numberof CHar) 

    // s1.append(s2); // Appends complete s2 string to the s1 string
    // s1.append(s2,0,3); // Appends s1 with 3 characters from 0th index of s2. 
    // s1.append(s2,2); // Appends s1 from 2nd index to end of s2.


    // when a constant char is appended then the following parameters shows the number of characters to be appended.
    // s1.append("Happy",2);


    // s1.append(s2.begin()+3,s2.end());// starting index to the end index +1


    // To string helps us to convert the int value to a string.
    // string n=to_string(23);
    // s1.append(n);

    // To append a single characte to a string.
    // s1.append(1,'a');//s1+='a';
 
    // to append multiple characters
    // s1.append(5,'%');

    cout << s1 << endl;


    return 0;
}