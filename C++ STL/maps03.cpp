#include<iostream>
#include<unordered_map>
using namespace std;

void print(unordered_map <int,string> &m){
    // Accessing each element O(n*1)
    for(auto &map_element : m){
        cout << map_element.first << " " << map_element.second << endl; // O(1)
    }
}

// Unordered Map and Multi Maps

int main(){
    // Inbuilt Implementation is using hash table
    unordered_map <int,string> m;

    m[1]="abc"; // Time Complexity O(1)
    m[5]="qwe";
    m[3]="acd";
    m[3]="sss";// contains only unique key 
    m.insert({4,"afd"});

    // print(m);

    // Find function of map
    auto it = m.find(4); // O(1)

    if(it == m.end()){
        cout << "No such element is present" << endl;
    }
    else{
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}