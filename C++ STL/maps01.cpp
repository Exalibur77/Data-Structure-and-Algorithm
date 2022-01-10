#include<vector>
#include<iostream>
#include<map>
using namespace std;

void print(map <int,string> &m){
    // Accessing each element O(n*logn)
    for(auto &map_element : m){
        cout << map_element.first << " " << map_element.second << endl; // O(logn)
    }
}

int main(){
    // Automatically stores in ascending order of the key using RED BLACK TREE 
    map <int,string> m;

    // Log(n) time insertion sololy depends upon the key type if key is string its insertion time will be s.size()*log(n)

    m[1]="abc"; // Time Complexity O(n) n is the current size of the map
    m[5]="qwe";
    m[3]="acd";
    m[3]="sss";// contains only unique key 
    m.insert({4,"afd"});

    // Find function of map
    auto it = m.find(4); // O(logn)

    // if(it == m.end()){
    //     cout << "No such element is present" << endl;
    // }
    // else{
    //     cout << it->first << " " << it->second << endl;
    // }

    // Erase function of map
    m.erase(5); //O(log n) using the key value
    
    // O(log n) using the iterator value of the pair which you want to delete
    if(it != m.end()){
        m.erase(it);
    }


    print(m);

}

