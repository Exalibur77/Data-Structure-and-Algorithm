#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> temp;
    
    for(int i=0; i<n; i++){
       
        int val = arr[i];

        auto it = lower_bound(temp.begin() , temp.end() , val);

        if(it == temp.end()){
            temp.push_back(val);
        }

        else{
            *it = val;
        }

    }
    
    return len;
}
    
