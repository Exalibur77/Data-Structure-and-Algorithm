#include<iostream>
using namespace std;

// Bitwise Operators

/*
Bitwise And &
Or |
XOr ^ (exculsive or rules a^a =0  a^b=1  a and b are bits)
negation or 1's complement  ~ (Formula ~x = -(x+1))
right shift >> (Formula  a>>b  a/2^b)
left shift <<  (Formula  a<<b  a*2^b)
*/

int main(){

    int a=5;
    int b=11;

    cout << (a&b) << endl;
    cout << (a|b) << endl;
    cout << (a^b) << endl;
    cout << (a^a) << endl; // always gives 0
    cout << (~a) << endl;
    cout << (~b) << endl;

    cout << (~0) << endl; // negation a number but not of a bit 
    cout << (~-3) << endl;

    cout << (b<<3) << endl; //b*2^3 = 11 * 8 = 88
    cout << (a>>1) << endl; // a/2^1 = 5/2 = 2
    cout << ((~0)<<2) << endl;
    return 0;
}