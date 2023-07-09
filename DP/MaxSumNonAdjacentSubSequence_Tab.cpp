#include<iostream>
#include<vector>

// House robber Problem
using namespace std;

int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    
    dp[0]= arr[0];
    
    for(int i=1 ;i<n; i++){

        int pick;

        if(index-2 < 0){
            pick = nums[index] + 0;
        }
        else{

            pick = nums[index] + dp[index-2];
        }


        int notPick = 0 + dp[index-1];

        dp[index] = max(pick , notPick);
    }
    
    
    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}


int main() {

  vector<int> arr{2,1,4,9};
  int n=arr.size();
  cout<<solve(n,arr);

}