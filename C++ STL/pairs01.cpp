#include<iostream>
#include<vector>

using namespace std;

int main(){

    // pair < int , string > p;

    // // Value Insertion
    // // p = make_pair(23,"qwe");
    // p={23,"qwe"};

    // // making copy of pair

    // pair <int,string> &p1 = p;// reference pair pointing to the same address as p.

    // p1.first=111;

    // cout << p.first << " " << p.second << endl;

    pair <int , vector<int> > p;

    p={1,{1,2,3}};

    cout << p.first << " " << endl;

    for(int val : p.second){
        cout << val << " ";
    }
    cout << endl;
}