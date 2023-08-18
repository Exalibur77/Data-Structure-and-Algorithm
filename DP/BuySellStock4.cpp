#include<iostream>
#include<vector>

using namespace std;



int f(int indx , int buy , int cap , vector<int> &prices , vector<vector<vector<int>>> &dp){

    if(cap == 0) return 0;

    if(indx == prices.size()) return 0;

    if(dp[indx][buy][cap] != -1) return dp[indx][buy][cap];

    int ans = 0;

    // I am free to buy a stock
    if(buy){

        int b = -prices[indx] + f(indx+1 , 0 , cap , prices,dp);
        int skip  = -0 + f(indx+1 , 1 , cap , prices,dp);

        ans = max(b,skip);
    }


    else{

        int s= +prices[indx] + f(indx+1 , 1 , cap-1 , prices,dp);
        int skip = +0 + f(indx+1 , 0 , cap , prices,dp);

        ans = max(s , skip);
    }

    return dp[indx][buy][cap] = ans;


}

int maxProfit(vector<int>& prices, int n , int k)
{
    // Creating a 3d - dp of size [n][2][k]
    vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>> 
                                            (2,vector<int>(k+1,-1)));
    
    return f(0,1,k,prices,dp);
   
}

int maxProfitTabulation(vector<int>& Arr, int n , int k)
{
    // Creating a 3d - dp of size [n+1][2][3] initialized to 0
    vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(k+1,0)));
                                            
    // As dp array is intialized to 0, we have already covered the base case
    
    for(int ind = n-1; ind>=0; ind--){ 

        for(int buy = 0; buy<=1; buy++){

            for(int cap=1; cap<=k; cap++){
                
                if(buy){// We can buy the stock

                    dp[ind][buy][cap] = max(0+dp[ind+1][1][cap], 
                                -Arr[ind] + dp[ind+1][0][cap]);
                                
                 }
    
                else{// We can sell the stock
                
                    dp[ind][buy][cap] = max(0+dp[ind+1][0][cap],
                                Arr[ind] + dp[ind+1][1][cap-1]);
                }
            }
        }
    }
    
    
    return dp[0][1][k];
   
}

int maxProfitSpaceOptimization(vector<int>& Arr, int n , int k)
{
    
    vector<vector<int>> ahead(2,vector<int> (k+1,0));
    
    
    
    for(int ind = n-1; ind>=0; ind--){
        
        vector<vector<int>> cur(2,vector<int> (k+1,0));

        for(int buy = 0; buy<=1; buy++){

            for(int cap=1; cap<=k; cap++){
                
                if(buy){// We can buy the stock
                    cur[buy][cap] = max(0+ahead[1][cap], 
                                -Arr[ind] + ahead[0][cap]);
                 }
    
                else{// We can sell the stock
                    cur[buy][cap] = max(0+ahead[0][cap],
                                Arr[ind] + ahead[1][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    
    return ahead[1][k];
   
}




int main() {

    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();

    int k = 10;
   
                                 
    cout<<"The maximum profit that can be generated is "<<maxProfit(prices, n , k) << endl;
    cout<<"The maximum profit that can be generated is "<<maxProfitTabulation(prices, n , k) << endl;
    cout<<"The maximum profit that can be generated is "<<maxProfitSpaceOptimization(prices, n , k) << endl;
}

