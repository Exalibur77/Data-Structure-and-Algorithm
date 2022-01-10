#include<iostream>
#include<string>
using namespace std;

int main(){
    // String Initilization

    // string b="Sanskar Garg";
    // string c("Welcome Home.. !");
    // string a(b); // Copy Constructor

    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;

    // // Input String

    // string s0,s1;
    // cin >> s0 ; // Cannot input complete sentence beacause the cin breaks at new line character or space
    // getline(cin,s1);

    // cout << s0 << endl;
    // cout << s1 << endl;

    // Iterate over string

    string str;
    getline(cin,str);

    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl; 

    for (auto it =str.begin(); it !=str.end(); it++)
    {
        cout << *it << "-";
    }
    cout << endl;

    for(char ch : str){
        cout << ch << ",";
    }
    cout << endl;

    

}