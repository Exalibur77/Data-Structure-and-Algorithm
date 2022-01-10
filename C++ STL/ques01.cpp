#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool comp(pair< string , int> p1 , pair< string , int> p2){

    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int main(){

    int n; cin >> n;
    vector < pair< string , int> > vp;

    string s;int marks;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> marks;
        vp.push_back({s,marks});
    }
    
    sort(vp.begin(),vp.end(),comp);

    for(auto &p : vp){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}