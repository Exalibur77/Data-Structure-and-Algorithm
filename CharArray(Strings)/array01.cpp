#include<iostream>
using namespace std;

int main(){

    // Creating an character array
    char arr[]={'a','b','c','\0'};// should always end with an null character

    // Printing an array.
    cout << arr << endl;

    char ch[]= "abc";// Automatically adds a null character at the end.

    cout << sizeof(arr) << " " << sizeof(ch) << endl; // Reads each element of the array.
    cout << strlen(arr) << " " << strlen(ch) << endl;// Reads only character present in the array.

    // Input the string in a character array

    char name[100];
    cin >> name ;

    cout << name << endl;

    return 0;
}