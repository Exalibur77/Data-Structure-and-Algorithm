#include<iostream>
#include<vector>
using namespace std;

// Vector Introduction

int main(){

    int n;
    cin >> n;

    vector <int> v(n);

    cout << "Enter vector elements" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // size of vector
    cout << v.size() << endl;
    max_element(v.begin(),v.end());
    // capacity of vector
    cout << v.capacity() << endl;

    v.push_back(11);

    // As soon as the size of the vector is altered by adding new elements , the capacity of the vector also increases to double the original size of the vector. 

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " " ;
    }
    cout << endl;


    return 0;
}