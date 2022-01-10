#include<iostream>
using namespace std;

// Calculate the number of spaces, number and alphabets in the given sentence.
int main(){

    char ch=cin.get();
    int alpha=0;
    int spaces=0;
    int number=0;
    int i=0;

    while(ch!='\n'){
        i++;
        if(ch==' ' or ch=='\t'){
           spaces++;
        } 

        else if(ch>='A' && ch<='Z' || ch>='a' && ch<='z'){
            alpha++;
        }

        else if(ch>='0' && ch<='9'){
            number++;
        }
        ch=cin.get();
    }

    cout << "Length =>" << i << endl;
    cout << "Numbers => " << number << endl;
    cout << "Spaces => " << spaces << endl;
    cout << "Aplhabets => " << alpha << endl;


    return 0;
}