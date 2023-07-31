#include<iostream>
#include<vector>

using namespace std;

int f(int indx , vector<int>& coins , int target , vector <vector <int>> &dp){

    if(indx == 0){

        if(target % coins[0] == 0) return 1;

        return 0;
    }

    if(dp[indx][target] != -1){
        return dp[indx][target];
    }

    int notTake = f(indx-1 , coins , target , dp);

    int take= 0;

    if(coins[indx] <= target){
        take = f(indx , coins , target-coins[indx] , dp);
    }

    return dp[indx][target] = take + notTake;
}


int countWaysToMakeChange(vector<int>& arr, int n, int T){
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));
    return f(n-1,arr, T, dp);
}

int countWaysToMakeChangeTabulation(vector<int>& coins, int n, int amount){
    
    vector <vector <int>> dp(n , vector<int>(amount+1 , -1));

        for(int target=0 ; target<= amount ; target++){
            if(target%coins[0] == 0) dp[0][target] = 1;

            else dp[0][target] = 0;
        }

        for(int indx = 1 ; indx <n ; indx++){

            for(int target = 0 ; target <= amount ; target++){

                int notTake = dp[indx-1][target];

                int take= 0;

                if(coins[indx] <= target){
                    take = dp[indx][target-coins[indx]];
                }

                dp[indx][target] = take + notTake;

            }

        }


        return dp[n-1][amount];
}


int main() {

  vector<int> arr ={1,2,3};
  int target=7;
  
  int n =arr.size();
                                 
  cout<<"The total number of ways is " <<countWaysToMakeChange(arr,n,target);
  cout<<"The total number of ways is " <<countWaysToMakeChangeTabulation(arr,n,target);
}