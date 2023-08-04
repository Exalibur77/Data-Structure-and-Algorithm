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




int minInsertions(string s) {

    int n = s.size();

    string s1 = s;

    reverse(s1.begin() , s1.end());

    vector < vector<int>> dp(n , vector<int>(n,-1));

    return n - lcs(n-1 , n-1 , s ,s1 , dp);


    
}



int main(){

    string str;    

    cin >> str;

    cout << minInsertions(str) << endl;

    return 0;
}