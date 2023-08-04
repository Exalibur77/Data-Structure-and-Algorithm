#include <iostream>
#include<vector>

using namespace std;

int lcs(int indx1 , int indx2 , string &s1 , string &s2 , vector <vector<int>> &dp){

    if(indx1 <0 or indx2 <0) return 0;

    if(dp[indx1][indx2] != -1) return dp[indx1][indx2];

    int ans = 0;

    // If character matches
    if(s1[indx1] == s2[indx2]){

        ans = 1 + lcs(indx1-1 , indx2-1 , s1 , s2 , dp);

    }

    else{

        int shrink1 = 0 + lcs(indx1-1 , indx2 , s1 , s2 , dp);

        int shrink2 = 0 + lcs(indx1 , indx2-1 , s1 , s2 , dp);

        ans = max(shrink1 , shrink2);
    }

    return dp[indx1][indx2] = ans;
}

int longestPalindromeSubsequence(string s){
    string t = s;
    reverse(s.begin(),s.end());
    return lcs(s,t);
}

int main() {

  string s= "bbabcbcab";
                                 
  cout<<"The Length of Longest Palindromic Subsequence is "<<
  longestPalindromeSubsequence(s);
}