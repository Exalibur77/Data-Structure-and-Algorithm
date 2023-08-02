#include <iostream>
#include <vector>

using namespace std;

int lcsTabulation(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    
    for(int i=0;i<=n;i++){
        dp[i][-1+1] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[-1+1][i] = 0;
    }
    
    for(int i = 0; i<n ; i++){

        for(int j=0 ; j<m ; j++){

            int ans = 0;

            if(s1[i] == s2[j]){
                ans = 1 + dp[i-1+1][j-1+1];
            }

            else{

                int shrink1 = dp[i-1+1][j+1];
                int shrink2 = dp[i+1][j-1+1];

                ans = max(shrink1 , shrink2);
            }

            dp[i+1][j+1] = ans;


        }
    }

    // Printing of LCS using the tabulation table made and backtracking from the last answer index n,m

    string ans;

    int i = n;
    int j = m;

    while(i>0 and j>0){

        // backtracking if indexes are equal just add into answer
        if(s1[i-1] == s2[j-1]){

            ans.push_back(s1[i-1]);
            i--;
            j--;

        }

        // If not equal just find from where it has come from , as it has two sources only

        // move towards the one have greater dp value
        else if(dp[i-1][j] > dp[i][j-1]){

            i = i-1;

        }

        else{
            j = j-1;
        }

    }

    // Since formulating answer from the end hence reverse it 
    reverse(ans.begin() , ans.end());

    cout << ans << endl;

    return dp[n][m];
}

int main() {

    string s1= "acd";
    string s2= "ced";
                                 
    cout<<"The Length of Longest Common Subsequence is "<<lcsTabulation(s1,s2) << endl;
}