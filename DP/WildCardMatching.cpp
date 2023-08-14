#include<iostream>
#include<string>
#include<vector>

using namespace std;


bool f(int i , int j , string &pattern, string &text , vector<vector<int>> &dp){

    if(i<0 and j<0) return true;

    if(i < 0) return false;

    // All star left from 0...i
    if(j < 0){

        for(int k=0 ; k<= i ; k++){
            if(pattern[k] != '*') return false;
        }

        return true;
        
    }
    

    if(dp[i][j] != -1) return dp[i][j];

    bool ans = false;

    // case - 1 .. and case 2
    if(pattern[i] == '?' or pattern[i] == text[j]){

        ans = f(i-1 , j-1 , pattern , text,dp);
    }


    // case:3 ... try out several different lengths substring
    if(pattern[i] == '*'){

        ans = f(i-1 , j , pattern , text , dp) or f(i , j-1 , pattern , text , dp);
    }

    return dp[i][j] = ans;

}


bool wildcardMatching(string pattern, string text) {
    
    int n = pattern.size();
    int m = text.size();

    vector <vector<int>> dp(n , vector<int>(m,-1));

    return f(n-1 , m-1 , pattern , text,dp);

}

bool isAllStar(string &pattern , int i){

    for(int x= 1 ; x<= i ; x++){

        if(pattern[x-1] != '*') return false;

    }

    return true;

}

bool wildcardMatchingTabulation(string pattern, string text) {
    
    int n = pattern.size();
    int m = text.size();

    vector <vector<int>> dp(n+1 , vector<int>(m+1,-1));

    dp[0][0] = true;

    // For i == -1
    for(int j=1 ; j<=m ; j++){
        dp[0][j] = false;
    }
    
    for(int i=1 ; i<=n ; i++){
        dp[i][0] = isAllStar(pattern , i);
    }

    for(int i=1 ; i<= n ; i++){

        for(int j=1 ; j<= m ; j++){

            bool ans = false;

            // case - 1 .. and case 2
            if(pattern[i-1] == '?' or pattern[i-1] == text[j-1]){

                ans = dp[i-1][j-1];
            }


            // case:3 ... try out several different lengths substring
            if(pattern[i-1] == '*'){

                ans = dp[i-1][j] or dp[i][j-1];
            }

            dp[i][j] = ans;

        }

    }


    return dp[n][m];

}

bool wildcardMatchingSpaceOptimised(string text, string pattern) {
        
    int n = pattern.size();
    int m = text.size();

    // vector <vector<int>> dp(n+1 , vector<int>(m+1,-1));
    vector <int> prev(m+1 , -1);

    prev[0] = true;

    // For i == -1
    for(int j=1 ; j<=m ; j++){
        prev[j] = false;
    }
    
    // for(int i=1 ; i<=n ; i++){
    //     dp[i][0] = isAllStar(pattern , i);
    // }

    for(int i=1 ; i<= n ; i++){

        vector <int> curr(m+1 , -1);

        curr[0] = isAllStar(pattern,i);

        for(int j=1 ; j<= m ; j++){

            bool ans = false;

            // case - 1 .. and case 2
            if(pattern[i-1] == '?' or pattern[i-1] == text[j-1]){

                ans = prev[j-1];
            }


            // case:3 ... try out several different lengths substring
            if(pattern[i-1] == '*'){

                ans = prev[j] or curr[j-1];
            }

            curr[j] = ans;

        }

        prev = curr;

    }


    return prev[m];

}







int main() {

    string S1 = "ab*cd";
    string S2 = "abdefcd";

    if (wildcardMatching(S1, S2)){
        cout << "String S1 and S2 match";
    }
    if (wildcardMatchingTabulation(S1, S2)){
        cout << "String S1 and S2 match";
    }
        

    else cout << "String S1 and S2 do not match";
}