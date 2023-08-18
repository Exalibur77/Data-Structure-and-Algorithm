#include<iostream>
#include<vector>
using namespace std;

int n,fees;

int f(int indx , int buy , vector<int>& prices , vector <vector<int>> &dp){

    if(indx == n) return 0;

    if(dp[indx][buy] != -1) return dp[indx][buy];

    int ans = 0;

    if(buy){

        int b = -prices[indx] + f(indx+1 , 0 , prices , dp);
        int skip = 0 + f(indx+1 , 1 , prices , dp);

        ans = max(b,skip);
    }

    else{

        int s = prices[indx] - fees + f(indx+1 , 1 , prices , dp);
        int skip = 0 + f(indx+1 , 0 , prices , dp);

        ans = max(s,skip);
    }

    return dp[indx][buy] = ans;


}

int maxProfit(vector<int>& prices, int fee) {
    
    n = prices.size();
    fees = fee;

    vector <vector<int>> dp(n , vector<int>(2,-1));

    return f(0 , 1 , prices ,dp);

}


int maxProfitTabulation(vector<int>& prices, int fee) {
        
    n = prices.size();
    fees = fee;

    vector <vector<int>> dp(n+1 , vector<int>(2,0));

    for(int indx= n-1 ; indx >=0 ; indx--){
        for(int buy = 0; buy <= 1 ; buy++){

            int ans = 0;

            if(buy){

                int b = -prices[indx] + dp[indx+1][0];
                int skip = 0 + dp[indx+1][1];

                ans = max(b,skip);
            }

            else{

                int s = prices[indx] - fees + dp[indx+1][1];
                int skip = 0 + dp[indx+1][0];

                ans = max(s,skip);
            }

            dp[indx][buy] = ans;

        }
    }

    return dp[0][1];

}

int maxProfitSpaceOptimised1(vector<int>& prices, int fee) {
        
    n = prices.size();
    fees = fee;

    vector<int> next(2,0);

    for(int indx= n-1 ; indx >=0 ; indx--){
        
        vector<int> curr(2,0);

        for(int buy = 0; buy <= 1 ; buy++){

            int ans = 0;

            if(buy){

                int b = -prices[indx] + next[0];
                int skip = 0 + next[1];

                ans = max(b,skip);
            }

            else{

                int s = prices[indx] - fees + next[1];
                int skip = 0 + next[0];

                ans = max(s,skip);
            }

            curr[buy] = ans;

        }

        next = curr;
    }

    return next[1];

}

int maxProfitSpaceOptimised2(vector<int>& prices, int fee) {
        
    n = prices.size();
    fees = fee;

    int nextBuy = 0;
    int nextSell = 0;

    for(int indx= n-1 ; indx >=0 ; indx--){
        
        int currBuy = 0;
        int currSell = 0;

        for(int buy = 0; buy <= 1 ; buy++){

            int ans = 0;

            if(buy){

                int b = -prices[indx] + nextSell;
                int skip = 0 + nextBuy;

                currBuy = max(b,skip);
            }

            else{

                int s = prices[indx] - fees + nextBuy;
                int skip = 0 + nextSell;

                currSell = max(s,skip);
            }

        }

        nextBuy = currBuy;
        nextSell = currSell;
    }

    return nextBuy;

}

int main(){

    vector <int> prices{1,3,2,8,4,9};

    int fee = 2;

    cout << "Max Profit is " << maxProfit(prices,fee) << endl;
    cout << "Max Profit is " << maxProfitTabulation(prices,fee) << endl;
    cout << "Max Profit is " << maxProfitSpaceOptimised1(prices,fee) << endl;
    cout << "Max Profit is " << maxProfitSpaceOptimised2(prices,fee) << endl;

}