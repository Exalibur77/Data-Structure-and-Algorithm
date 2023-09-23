#include <iostream>
#include <vector>

using namespace std;

int f(int i , int j , vector<int> &arr , vector<vector<int>> &dp){

    // base case
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int maxi = INT_MIN;

    // Assuming this k th ballon is burst at the end 
    for(int k = i ; k<= j ; k++){

        int currAns = arr[i-1] * arr[k] * arr[j+1] + f(i , k-1 , arr,dp) + f(k+1 , j , arr,dp); 

        maxi= max(maxi , currAns);

    }

    return dp[i][j] = maxi;


}
int maxCoins(vector<int> &a) {

    int n = a.size();

    a.push_back(1);

    a.insert(a.begin(), 1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return f(1, n, a, dp);
}

int maxCoinsTabulation(vector<int>& arr) {
        
    int n = arr.size();

    // arr.insert(arr.begin() , 1);
    // arr.push_back(1);


    vector <vector <int>> dp(n+2 , vector <int>(n+2 , 0));

    for(int i = n ; i >= 1; i--){

        for(int j=i ; j<= n ; j++){

            int maxi = INT_MIN;

            // Assuming this k th ballon is burst at the end 
            for(int k = i ; k<= j ; k++){

                int currAns = arr[i-1] * arr[k] * arr[j+1] + dp[i][k-1] + dp[k+1][j];

                maxi= max(maxi , currAns);

            }


            dp[i][j] = maxi;

        }


    }

    return dp[1][n];


}

int main() {

    vector<int> a = {3, 1, 5, 8};
    int ans = maxCoins(a);
    cout << ans << "\n";

    cout << maxCoinsTabulation(a) << endl;
}