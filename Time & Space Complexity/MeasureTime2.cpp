#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

// using chrono library

int main(){

    int n; cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i]=int(random()%1000);
    }
    
    auto start = high_resolution_clock::now();

    sort(v.begin(),v.end());

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end-start);

    cout << duration.count() << endl;
    




}