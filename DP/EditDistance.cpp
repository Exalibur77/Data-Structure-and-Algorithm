#include<iostream>
#include<string>
#include<vector>

using namespace std;


 
int f(int i , int j , string &s1 , string &s2 , vector <vector<int>> &dp){

    // if j gets over means there are still some characters left in s1 , so delete them up
    if(j ==  -1) return (i+1);

    // if my i gets over but j is still shaving some more characters to be equal so insert them up 
    if(i  == -1) return (j+1);

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    // Both the characters are matching
    if(s1[i] == s2[j]){

        ans = 0 + f(i-1 , j-1 , s1 , s2 , dp);

    }

    // not match , so two options are there
    else{

        int replace = 1 + f(i-1 , j-1,s1,s2 , dp);
        int del = 1 + f(i-1 , j , s1 , s2 , dp);
        int insert = 1 + f(i , j-1 , s1 , s2 , dp);

        ans = min({replace , del , insert});
    }

    return dp[i][j] = ans;

}


int editDistance(string word1, string word2) {
    
    int n = word1.size();
    int m = word2.size();

    vector < vector<int>> dp(n , vector <int>(m,-1));

    return f(n-1 , m-1 , word1 , word2 , dp);


}

int editDistanceTabulation(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();

    vector < vector<int>> dp(n+1 , vector <int>(m+1,-1));

    // First store negative base cases

    // for j== -1 case and origin shifting
    for(int i=0 ; i<= n ; i++){
        dp[i][0] = i;
    }


    for(int j=0 ; j<= m ; j++){
        dp[0][j] = j;
    }

    // dp[0][0] = 0;

    for(int i= 1; i<= n ; i++){

        for(int j=1 ; j<= m ; j++){

            int ans = 0;

            // Both the characters are matching
            if(s1[i-1] == s2[j-1]){

                ans = 0 + dp[i-1][j-1];

            }

            // not match , so two options are there
            else{

                int replace = 1 + dp[i-1][j-1];
                int del = 1 + dp[i-1][j];
                int insert = 1 + dp[i][j-1];

                ans = min({replace , del , insert});
            }

                dp[i][j] = ans;

        }

    }

    return dp[n][m];
}

int editDistanceTabulationSpace(string s1, string s2) {

    int n = s1.size();
    int m = s2.size(); 

    vector <int> prev(m+1,-1);

    for(int j=0 ; j<= m ; j++){
        prev[j] = j;
    }

    for(int i= 1; i<= n ; i++){

        vector <int> curr(m+1 , -1);
        curr[0] = i;

        for(int j=1 ; j<= m ; j++){

            int ans = 0;

            // Both the characters are matching
            if(s1[i-1] == s2[j-1]){

                ans = 0 + prev[j-1];

            }

            // not match , so two options are there
            else{

                int replace = 1 + prev[j-1];
                int del = 1 + prev[j];
                int insert = 1 + curr[j-1];

                ans = min({replace , del , insert});
            }

                curr[j] = ans;

        }

        prev = curr;

    }

    return prev[m];
}



int main() {

    string s1 = "horse";
    string s2 = "ros";

     cout << "The minimum number of operations required is: "<< editDistance(s1,s2) << endl;
     cout << "The minimum number of operations required is: "<< editDistanceTabulation(s1,s2) << endl;
     cout << "The minimum number of operations required is: "<< editDistanceTabulationSpace(s1,s2) << endl;
}