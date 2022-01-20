#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

// using C time Library

int main(){

    int n; cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i]=int(random());
    }
    
    auto start = clock();

    sort(v.begin(),v.end());

    auto end = clock();

    cout << end - start << endl;
     // This value is in microseconds




}