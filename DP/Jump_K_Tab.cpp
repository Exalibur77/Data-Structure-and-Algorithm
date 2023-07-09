#include <iostream>
#include <vector>

using namespace std;


int main() {

    vector<int> height{30,10,60,10,60,50};

    int n=height.size();

    vector<int> dp(n,-1);

    dp[0]=0;

    for(int ind=1;ind<n;ind++){

        int mini = INT_MAX;

        for(int back = 1 ; back<=k ; back++){

            if(ind-back >= 0){

                int cost = dp[ind-back] + abs(height[ind] - height[ind-back]);

                mini = min(mini , cost);

            }

        }

        dp[ind] = mini;
       
    }

    cout<<dp[n-1];
}
