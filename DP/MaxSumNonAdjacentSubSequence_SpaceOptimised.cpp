#include<iostream>
#include<vector>

// House robber Problem

using namespace std;

int solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick;

        if(index-2 < 0){
            pick = nums[index] + 0;
        }
        else{

            pick = nums[index] + prev2;
        }


        int notPick = 0 + prev;

        int curr = max(pick , notPick);

        prev2 = prev;
        prev = curr;
        
    }
    return prev;
}


int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);

}