#include<iostream>
#include<vector>

using namespace std;

int f(int len , vector<int> &price , int target , vector <vector<int>> &dp){

	if(len == 1){
		return price[0]*target;
	}

	if(dp[len][target] != -1){
		return dp[len][target];
	}

	int notTake = 0 + f(len-1 , price , target , dp);

	int take = INT_MIN;

	if(target >= len){
		take = price[len-1] + f(len, price , target-len , dp);
	}

	return dp[len][target]= max(take , notTake);

}

int cutRod(vector<int> &price, int n)
{
	
	vector <vector<int>> dp(n+1 , vector<int>(n+1 , -1));

	return f(n , price , n , dp);

}

int cutRodTabulation(vector<int> &price, int n){


	vector <vector<int>> dp(n+1 , vector<int>(n+1 , -1));

    for(int target = 0 ; target <= n ; target++){

        dp[1][target] = target*price[1-1];

    }


    for(int len = 2; len <= n ; len++){

        for(int target = 0 ; target <= n ; target++){

            int notTake = 0 + dp[len-1][target];

            int take = INT_MIN;

            if(target >= len){
                take = price[len-1] + dp[len][target-len];
            }

            dp[len][target]= max(take , notTake);
        }

    }

    return dp[n][n];


}


int main() {

  vector<int> price = {2,5,7,8,10};
  
  int n = price.size();
                                 
  cout<<"The Maximum price generated is "<<cutRod(price,n);
  cout<<"The Maximum price generated is "<<cutRodTabulation(price,n);
}