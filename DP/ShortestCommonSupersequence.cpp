#include<iostream>
#include<vector>

// Size of Supersequence = n + m - LCS(removing the longest common subsequence once to remove the duplicate)


string shortestSupersequence(string s1, string s2) {
        
    // this part is LCS tabulation way

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){

        for(int ind2=1;ind2<=m;ind2++){

            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];

            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);

        }
    }
    
    string ans = "";

    // Now DP table is being created

    // Backtracking to find the string in the similar fashion as done to print LCS
    int i = n;
    int j = m;

    while(i>0 and j>0){

        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }

        // Moving up
        else if(dp[i-1][j] > dp[i][j-1]){
            
            // taking the ith character from s1 by 1 based indx
            ans += s1[i-1];
            i--;

        }

        // Moving left
        else{

            ans += s2[j-1];
            j--;
        }


    }

    // Now no of characters that are left to be added in either one of them

    while(i>0){
        ans += s1[i-1];
        i--;
    }

    while(j >0){
        ans += s2[j-1];
        j--;
    }

    reverse(ans.begin() , ans.end());
    // reverse the answer since it is being formed in the reverse fashion from the end

    return ans;
}


int main() {

  string s1 = "brute";
  string s2 = "groot";

  cout << "The Longest Common Supersequence is "<<shortestSupersequence(s1,s2);
}