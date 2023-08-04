#include <iostream>
#include<vector>

using namespace std;

int longestCommonSubstring(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    for(int i=0 ; i<=n ; i++){
        dp[i][0] = 0;
    }

    for(int j = 0; j<=m ; j++){
        dp[0][j] = 0;
    }
    
    int max_i , max_j;

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                
                if(dp[i][j] > ans){
                    ans = dp[i][j];

                    max_i = i;
                    max_j = j;
                }
            }

            else
                dp[i][j] = 0;
        }
    }

    // Printing the subarray

    string res;

    while(dp[max_i][max_j] != 0){

        res.push_back(s1[max_i-1]);

        max_i--;
        max_j--;
    }



    reverse(res.begin() , res.end());

    cout << res << endl;
    
    return ans;
    
}



int longestCommonSubstringSpace(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    
    vector <int> prev(m+1,0);

    int ans = 0;
    
    for(int i=1;i<=n;i++){

        vector <int> curr(m+1 , 0);

        for(int j=1;j<=m;j++){

            if(s1[i-1]==s2[j-1]){

                int val = 1 + prev[j-1];
                curr[j] = val;
                ans = max(ans,val);

            }
            else
                curr[j] = 0;
        }

        prev = curr;
    }
    
    return ans;
    
}

int main() {

  string s1= "abcjklp";
  string s2= "acjkp";
                                 
  cout<<"The Length of Longest Common Substring is "<<longestCommonSubstring(s1,s2);
  cout<<"The Length of Longest Common Substring is "<<longestCommonSubstringSpace(s1,s2);
}
