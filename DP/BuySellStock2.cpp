#include<iostream>
#include<vector>

using namespace std;

int f(int indx , int buy , vector<int>& prices , vector<vector<int>> &dp){

    if(indx == prices.size()) return 0;

    if(dp[indx][buy] != -1) return dp[indx][buy];

    int ans = 0;
    

    // If i am free to buy
    if(buy){

        // 2 options whether I buy or just dont buy

        int b = (-prices[indx]) + f(indx+1 , 0 , prices , dp);
        int nb = -0 + f(indx+1 , 1 , prices , dp);

        ans = max(b,nb);

    }

    // I am free to sell
    else{

        // Again 2 options whether sell or not sell
        int s = (prices[indx]) + f(indx+1 , 1 , prices , dp);
        int ns = (0) + f(indx+1 , 0 , prices , dp);

        ans = max(s,ns);

    }

    return dp[indx][buy] = ans;

}


int maxProfit(vector<int>& prices) {
    
    int n = prices.size();

    vector <vector<int>> dp(n , vector<int>(2,-1));

    return f(0 , 1 , prices ,dp);

}

int maxProfitTabulation(vector<int>& prices) {
        
    int n = prices.size();

    vector <vector<int>> dp(n+1 , vector<int>(2,-1));

    dp[n][0] = 0;
    dp[n][1] = 0;

    for(int indx = n-1 ; indx >=0 ; indx--){

        for(int buy = 0 ; buy <= 1; buy++){

            int ans = 0;

            // If i am free to buy
            if(buy){

                // 2 options whether I buy or just dont buy

                int b = (-prices[indx]) + dp[indx+1][0];
                int nb = -0 + dp[indx+1][1];

                ans = max(b,nb);

            }

            // I am free to sell
            else{

                // Again 2 options whether sell or not sell
                int s = (prices[indx]) + dp[indx+1][1];
                int ns = (0) + dp[indx+1][0];

                ans = max(s,ns);

            }

            dp[indx][buy] = ans;


        }

    }



    return dp[0][1];

}

int maxProfitSpaceOptimised(vector<int>& prices) {
        
    int n = prices.size();

    vector <vector<int>> dp(n+1 , vector<int>(2,-1));

    vector <int> nxt(2,-1);

    nxt[0] = 0;
    nxt[1] = 0;

    for(int indx = n-1 ; indx >=0 ; indx--){

        vector <int> curr(2,-1);

        for(int buy = 0 ; buy <= 1; buy++){

            int ans = 0;

            // If i am free to buy
            if(buy){

                // 2 options whether I buy or just dont buy

                int b = (-prices[indx]) + nxt[0];
                int nb = -0 + nxt[1];

                ans = max(b,nb);

            }

            // I am free to sell
            else{

                // Again 2 options whether sell or not sell
                int s = (prices[indx]) + nxt[1];
                int ns = (0) + nxt[0];

                ans = max(s,ns);

            }

            curr[buy] = ans;


        }

        nxt = curr;

    }

    return nxt[1];

}


int maxProfitSpaceOptimisedVariable(vector<int>& prices) {
        
    int n = prices.size();

    // vector <vector<int>> dp(n+1 , vector<int>(2,-1));

    // vector <int> nxt(2,-1);

    int nxtNotBuy = 0;
    int nxtBuy = 0;

    for(int indx = n-1 ; indx >=0 ; indx--){

        int currNotBuy = 0;
        int currBuy = 0;

        for(int buy = 0 ; buy <= 1; buy++){

            int ans = 0;

            // If i am free to buy
            if(buy){

                // 2 options whether I buy or just dont buy

                int b = (-prices[indx]) + nxtNotBuy;
                int nb = -0 + nxtBuy;

                currBuy = max(b,nb);

            }

            // I am free to sell
            else{

                // Again 2 options whether sell or not sell
                int s = (prices[indx]) + nxtBuy;
                int ns = (0) + nxtNotBuy;

                currNotBuy = max(s,ns);

            }

            


        }

        nxtNotBuy = currNotBuy;
        nxtBuy = currBuy;

    }



    return nxtBuy;

}

int main() {

    int n =6;
    vector<int> arr= {7,1,5,3,6,4};
                                    
    cout<< " The maximum profit that can be generated is " << maxProfit(arr) << endl;
}