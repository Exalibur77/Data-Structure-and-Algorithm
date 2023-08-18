#include<iostream>
#include<vector>
using namespace std;


int f(int indx , int buy , vector<int>& prices , vector <vector <int>> &dp){
 
    if(indx >= prices.size()) return 0;

    if(dp[indx][buy] != -1) return dp[indx][buy];

    int ans = 0;


    // I am free to buy
    if(buy){

        int b = (-prices[indx] + f(indx+1 , 0 , prices ,dp));
        int skip = 0 + f(indx+1 , 1 , prices ,dp);

        ans = max(b , skip);

    }

    // I am free to sell
    else{

        int s = (prices[indx] + f(indx+2 ,1 ,prices , dp));
        int skip = 0 + f(indx+1 , 0 , prices , dp);

        ans = max(s , skip);
    }

    return dp[indx][buy] = ans;

}

int maxProfitTabulation(vector<int>& prices) {
    
    int n = prices.size();

    vector <vector <int>> dp(n+2 , vector<int>(2,0));

    for(int indx = n-1 ;  indx >= 0 ; indx--){

        for(int buy = 0; buy <=1 ; buy++){

            int ans = 0;

            // I am free to buy
            if(buy){

                int b = (-prices[indx] + dp[indx+1][0]);
                int skip = 0 +  dp[indx+1][1];

                ans = max(b , skip);

            }

            // I am free to sell
            else{

                int s = (prices[indx] +  dp[indx+2][1]);
                int skip = 0 +  dp[indx+1][0];

                ans = max(s , skip);
            }

            dp[indx][buy] = ans;
        }

    }



    return dp[0][1];
}

int maxProfitSpaceOptimised(vector<int>& prices) {
    
    int n = prices.size();

    vector<int> front1(2,0);
    vector<int> front2(2,0);

    for(int indx = n-1 ;  indx >= 0 ; indx--){

        vector<int> curr(2,0);


        for(int buy = 0; buy <=1 ; buy++){

            int ans = 0;

            // I am free to buy
            if(buy){

                int b = (-prices[indx] + front1[0]);
                int skip = 0 +  front1[1];

                ans = max(b , skip);

            }

            // I am free to sell
            else{

                int s = (prices[indx] +  front2[1]);
                int skip = 0 +  front1[0];

                ans = max(s , skip);
            }

            curr[buy] = ans;
        }

        front2 = front1;
        front1 = curr;
    }



    return front1[1];

}


int maxProfit(vector<int>& prices) {

    int n = prices.size();

    vector <vector <int>> dp(n , vector<int>(2,-1));

    return f(0 , 1 , prices , dp);

}

int main() {

    vector<int> prices {4,9,0,4,10};
                                 
    cout<<"The maximum profit that can be generated is "<< maxProfit(prices);
    cout<<"The maximum profit that can be generated is "<< maxProfitTabulation(prices);
    cout<<"The maximum profit that can be generated is "<< maxProfitSpaceOptimised(prices);
}