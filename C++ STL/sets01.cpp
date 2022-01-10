#include<iostream>
#include<string>
#include<set>
using namespace std;

void print(set <string> s){

    for(auto &str : s){
        cout << str << " ";
    }
    cout << endl;

    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    

}

// Normal Sets 
int main(){

    // Sets stores unique key elements in a sorted order
    set <string> s; // also use Red Black Tress for its implementation

    s.insert("abc"); // log(n)
    s.insert("pqr");
    s.insert("aaa");
    s.insert("abc");

    print(s);

    auto it = s.find("abc"); // O(logn)

    if(it != s.end()){
        cout << *it << endl;
    }

    // s.erase(it); or s.erase("abc")

    print(s);

    return 0;
}
