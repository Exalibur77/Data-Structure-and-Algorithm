#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Open() and Eof() functions 

int main(){

    ofstream out;
    out.open("file2.txt",ios::app); // this means ofstream object out is opened in a append mode.

    if(out.is_open()){

        string name;
        cout <<  "Enter your name : "; 
        getline(cin,name);

        // putting or ouptuting name in file2
        out << "\nYour name is " <<  name << ".";

    }

    out.close();

    // Reading file 
    ifstream in("file2.txt");
    string x;
    
    // return true if i am at eof(eof of file). 
    while(in.eof() == 0){

        getline(in,x);
        cout << x << endl;

    }

    in.close();

    return 0;
}