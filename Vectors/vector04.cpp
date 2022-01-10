#include<iostream>
#include "vector.h"

using namespace std;

int main(){

    vector <int>v;

    vector <char> vc;

    vc.push_back('a');
    vc.push_back('e');
    vc.push_back('i');
    vc.push_back('o');
    vc.push_back('u');

    for (int i = 0; i < vc.size(); i++)
    {
        cout << vc[i] << " ";
    }
    cout << endl;

    v.push_back(12);
    v.push_back(1212);
    v.push_back(2);
    v.push_back(1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    

    return 0;
}