#include<iostream>
#include<map>
using namespace std;
/*
Given N strings , print unique strings in lexographical
order with their frequenncy

N <= 10^5
|S| <= 100

*/

int main(){

    map < string,int> m;
    int n;cin >> n;
    string s;
    // O(n* log(n))
    for (int i = 0; i < n; i++)
    {
        // If we write m[s] it automatically stores 0 as a value of the given key.
        cin >> s;
        m[s]++;

    }
    cout << endl;
    cout << "KEY" << "    " << "Frequency" << endl;
    for(auto &p : m){
        cout << p.first << " " << p.second << endl;
    }




    return 0;
}