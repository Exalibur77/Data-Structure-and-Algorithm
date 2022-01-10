#include<iostream>
// #include<vector>
#include<algorithm>
using namespace std;

int main(){

    vector< vector<int> > v;
    v.push_back({1,2});    

    for(auto &vec : v){
        for(int &val : vec){
            cout << val << " ";
        }
    }

    return 0;
}