#include <iostream>
#include <vector>

using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp , int k){

    if(ind==0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int mini = INT_MAX;

    for(int back = 1 ; back<=k ; back++){

        if(ind-back >= 0){

            int cost = solve(ind - back , height , dp , k) + abs(height[ind] - height[ind-back]);

            mini = min(mini , cost);

        }

    }

    
    return dp[ind]=mini;
}


int main() {

    vector<int> height{10, 30, 40, 50, 20};

    int n=height.size();

    int k = 3;

    vector<int> dp(n,-1);

    cout<<solve(n-1,height,dp ,k);

    return 0;
}