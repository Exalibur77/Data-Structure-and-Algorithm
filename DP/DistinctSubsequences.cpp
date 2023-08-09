#include<iostream>
#include<vector>

using namespace std;

int f(int i , int j , string &str, string &sub , vector<vector<int>>&dp){

    // Base case
    if(j < 0) return 1;

    // no such subsequence exists 
    if(i < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    // if character matches , then there are two possibilities

    if(str[i] == sub[j]){

        int take = f(i-1 , j-1 , str , sub,dp);
        int notTake = f(i-1 , j , str , sub, dp);
        // while not takeing current ith current as we are trying to find another occurenece of same sub[j] in the remaining left part

        ans = take + notTake;
    }

    // character does not matches , so just reduce the main string by 1 
    else{

        ans = f(i-1 , j , str , sub ,dp);
    }


    return dp[i][j] = ans;

}


int subsequenceCounting(string &s1 , string &s2 , int n , int m){

    vector <vector<int>> dp(n , vector<int>(m,-1));    

    return f(n-1,m-1,s1,s2,dp);

}

int subsequenceCountingTabulation(string &s , string &t , int n , int m){

    if(m > n) return 0;

    vector <vector<double>> dp(n+1,vector <double>(m+1,-1));

    // Now tabulating

    //1 . Initialsing the base case 

    for(int j=0; j<= m ; j++){
        dp[0][j] = 0;
    }

    for(int i=0 ; i<=n ; i++){
        dp[i][0] = 1;
    }

    for(int i=1 ; i<=n ; i++){

        for(int j=1 ; j<=m ; j++){

            double ans = 0;

            // if character matches , then there are two possibilities

            if(s[i-1] == t[j-1]){

                double take = dp[i-1][j-1];
                double notTake = dp[i-1][j];

                // while not takeing current ith current as we are trying to find another occurenece of same sub[j] in the remaining left part

                ans = take + notTake;
            }

            // character does not matches , so just reduce the main string by 1 
            else{

                ans = dp[i-1][j];
            }


            dp[i][j] = ans;

        }

    }

    return (int)dp[n][m];


}

int subsequenceCountingSO1(string &s , string &t , int n , int m){



    if(m > n) return 0;

    vector <double> prev(m+1 , 0);

    prev[0] = 1;

    for(int i=1 ; i<=n ; i++){

        vector <double> curr(m+1 , 0);
        curr[0] = 1;

        for(int j=1 ; j<=m ; j++){

            double ans = 0;

            // if character matches , then there are two possibilities

            if(s[i-1] == t[j-1]){

                double take = prev[j-1];
                double notTake = prev[j];

                // while not takeing current ith current as we are trying to find another occurenece of same sub[j] in the remaining left part

                ans = take + notTake;
            }

            // character does not matches , so just reduce the main string by 1 
            else{

                ans = prev[j];
            }


            curr[j] = ans;

        }

        prev = curr;
    }

    return (int)prev[m];

}

int subsequenceCountingSO2(string &s , string &t , int n , int m){



    if(m > n) return 0;

    vector <double> prev(m+1 , 0);

    prev[0] = 1;

    for(int i=1 ; i<=n ; i++){

        for(int j=m ; j >= 1 ; j--){

            double ans = 0;

            // if character matches , then there are two possibilities

            if(s[i-1] == t[j-1]){

                double take = prev[j-1];
                double notTake = prev[j];

                // while not takeing current ith current as we are trying to find another occurenece of same sub[j] in the remaining left part

                ans = take + notTake;
            }

            // character does not matches , so just reduce the main string by 1 
            else{

                ans = prev[j];
            }


            prev[j] = ans;

        }
    }

    return (int)prev[m];

}


int main() {

  string s1 = "babgbag";
  string s2 = "bag";

  cout << "The Count of Distinct Subsequences is " <<subsequenceCounting(s1,s2,s1.size(),s2.size()) << endl;
  cout << "The Count of Distinct Subsequences is " <<subsequenceCountingTabulation(s1,s2,s1.size(),s2.size()) << endl;
  cout << "The Count of Distinct Subsequences is " <<subsequenceCountingSO1(s1,s2,s1.size(),s2.size()) << endl;
  cout << "The Count of Distinct Subsequences is " <<subsequenceCountingSO2(s1,s2,s1.size(),s2.size()) << endl;
}