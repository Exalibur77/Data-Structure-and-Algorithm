#include<iostream>
using namespace std;

// Reference Variable (two names for calling the same variable or same address )
int main(){

    // int x=10;
    // int & y= x;

    // y++;

    // cout << x << endl;
    // cout << y << endl;


    int i=10;
    int &j=i;

    j++;

    cout << i << " " << j << endl;

    i++;

    cout << i << " " << j << endl;

    int k=100;
    j=k;

    j++;

    cout << j << " " << k  << endl;
    cout << i << endl;



    return 0;
}