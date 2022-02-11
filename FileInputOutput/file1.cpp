#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*
fstream class contains three classes :

1. fstreambase
2. ifstream -- derived from fstreambase
3. ofstream -- derived from fstreambase
*/

// There are two ways to open a file :

// 1. Using constructor of the class
// 2. Using open() member function

int main(){

    // output dedo file ko
    // ofstream out("file1.txt");

    // out << "Harry Bhai";

    string x;

    // Opening file1.txt using the constructor of ifstream (helps in inputting data from file to program)
    
    // input lelo file se or Read karlo file se
    ifstream in("file1.txt");

    // in>>x; // for first word

    getline(in,x);

    cout << endl;
    cout << x << endl;
    
    
    




}