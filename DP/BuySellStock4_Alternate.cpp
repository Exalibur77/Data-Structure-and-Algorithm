#include<iostream>
#include<vector>

using namespace std;

int f(int indx , int transactionIndex , vector<int>& prices , vector <vector<int>> &dp , int k){

    if(indx == prices.size() or transactionIndex == 2*k) return 0;

    if(dp[indx][transactionIndex] != -1) return dp[indx][transactionIndex];

    int ans = 0;

    // Even Case .. means a BUY case
    if(transactionIndex%2 == 0){

        int b = -prices[indx] + f(indx+1 , transactionIndex+1 , prices,dp ,k);
        int skip = f(indx+1 , transactionIndex , prices,dp ,k);
            
        ans = max(b , skip);
        
    }
    
    else{


        int s = prices[indx] + f(indx+1 , transactionIndex+1 , prices,dp,k);
        int skip = f(indx+1 , transactionIndex , prices,dp,k);
            
        ans = max(s , skip);
    
    }


    return dp[indx][transactionIndex] =ans;

    
}


int maxProfit(vector<int>& prices , int n , int k)
{

    vector <vector<int>> dp(n , vector<int>(2*k+1,-1));

    return f(0 , 0 , prices , dp , k);
}



int maxProfitTabulation(vector<int>& prices , int n , int k)
{
    // int n = prices.size();

    vector <vector<int>> dp(n+1 , vector<int>(2*k+1,-1));

    // Storing base case
    for(int transactionIndx = 0 ; transactionIndx < 2*k+1 ; transactionIndx++){
        dp[n][transactionIndx] = 0;
    }

    for(int indx = 0 ; indx <= n ; indx++){
        dp[indx][2*k] = 0;
    }

    for(int indx = n-1 ; indx >= 0 ; indx--){

        for(int transactionIndx = 2*k-1 ; transactionIndx >= 0 ; transactionIndx--){

            int ans = 0;

            // Even Case .. means a BUY case
            if(transactionIndx%2 == 0){

                int b = -prices[indx] + dp[indx+1][transactionIndx+1];
                int skip = dp[indx+1][transactionIndx];
                    
                ans = max(b , skip);
                
            }
            
            else{


                int s = prices[indx] + dp[indx+1][transactionIndx+1];
                int skip = dp[indx+1][transactionIndx];
                    
                ans = max(s , skip);
            
            }


            dp[indx][transactionIndx] =ans;



        }


    }



    return dp[0][0];
}

int maxProfitSpaceOptimization(vector<int>& prices , int n , int k)
{
    // int n = prices.size();

    vector<int> next(2*k+1,0);

    for(int indx = n-1 ; indx >= 0 ; indx--){

        vector<int> curr(2*k+1,0);


        for(int transactionIndx = 2*k-1 ; transactionIndx >= 0 ; transactionIndx--){

            int ans = 0;

            // Even Case .. means a BUY case
            if(transactionIndx%2 == 0){

                int b = -prices[indx] + next[transactionIndx+1];
                int skip = next[transactionIndx];
                    
                ans = max(b , skip);
                
            }
            
            else{


                int s = prices[indx] + next[transactionIndx+1];
                int skip = next[transactionIndx];
                    
                ans = max(s , skip);
            
            }


            curr[transactionIndx] =ans;



        }

        next = curr;

    }



    return next[0];
}

int main() {

    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();

    int k = 10;
                                 
    cout<<"The maximum profit that can be generated is "<<maxProfit(prices, n ,k) << endl;
    cout<<"The maximum profit that can be generated is "<<maxProfitTabulation(prices, n,k) << endl;
    cout<<"The maximum profit that can be generated is "<<maxProfitSpaceOptimization(prices, n,k) << endl;
}

