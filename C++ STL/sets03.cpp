#include<iostream>
#include<string>
#include<set>
using namespace std;

void print(multiset <string> s){

    for(auto &str : s){
        cout << str << " ";
    }
    cout << endl;
}


// Multi Sets can used in place of priority queues 
int main(){
 
    // Multi Sets stores key elements in a sequential order
    multiset <string> s; //uses Red Black Trees for its implementation

    s.insert("abc"); // log(n)
    s.insert("pqr");
    s.insert("aaa");
    s.insert("abc");

    print(s);

    auto it = s.find("abc"); // O(logn)

    // if(it != s.end()){
    //     cout << *it << endl;
    // }

    // Erase function in multiset works differently in both cases

    // s.erase(it); // erases the first abc 
    s.erase("abc"); // erases all the abc string present in the given multiset.

    print(s);

    return 0;
}
