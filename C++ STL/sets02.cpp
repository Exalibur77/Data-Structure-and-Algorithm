#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

void print(unordered_set <string> s){

    for(auto &str : s){
        cout << str << " ";
    }
    cout << endl;
    

}

// Unordered Sets 
int main(){

    // Sets stores unique key elements in a random order
    unordered_set <string> s; //uses Hash Tables for its implementation

    s.insert("abc"); // log(1)
    s.insert("pqr");
    s.insert("aaa");
    s.insert("abc");

    print(s);

    auto it = s.find("abc"); // O(1)

    if(it != s.end()){
        cout << *it << endl;
    }

    // s.erase(it); or s.erase("abc")

    print(s);

    return 0;
}
