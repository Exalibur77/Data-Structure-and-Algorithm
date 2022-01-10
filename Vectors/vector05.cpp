#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector <int> arr = {10,11,2,3,45,34,2};

    int key=31;

    // vector <int> :: iterator it=find(arr.begin(),arr.end(),key);
    // or use auto
    auto it=find(arr.begin(),arr.end(),key);// O(n) solution

    if(it == arr.end()){
        cout << "Not Present .. !" << endl;
    }
    else{
        cout << key << " is present at the index => " << it-arr.begin() << endl;
    }

    return 0;
}