#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){

    ofstream out("file2.txt");

    string name;
    cout <<  "Enter your name : "; 
    getline(cin,name);

    // putting or ouptuting name in file2
    out << "My name is " <<  name;

    out.close();

    // Reading file 
    ifstream in("file2.txt");
    string x;
    getline(in,x);

    cout << x << endl;

    in.close();

    return 0;
}