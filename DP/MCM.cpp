#include <iostream>
#include<vector>

using namespace std;

int f(int i , int j , int *arr , vector <vector<int>> &dp){

    // base case .. means a single matrix is there
    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int minAns = 1e9;

    // Now try to add partition randomly at any position between i to j-1

    for(int k = i ;  k <= j-1 ; k++){

        int ans = arr[k] * arr[i-1] * arr[j] + f(i , k , arr,dp) + f(k+1 , j , arr,dp);

        minAns = min(ans , minAns);

    }

    return dp[i][j] = minAns;

}




int matrixChainMultiplication(int* arr, int n) {

    vector <vector <int>> dp(n , vector <int>(n ,-1));

    return f(1 , n-1 , arr , dp);

}

int matrixChainMultiplicationTabulation(int* arr, int n) {

    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    for(int i=1; i<=n-1; i++){
        dp[i][i] = 0;
    }
    
    for(int i=n-1; i>=1; i--){
        
        for(int j=i+1; j<=n-1; j++){
            
            int mini = INT_MAX;
    
            // partioning loop
            for(int k = i; k<= j-1; k++){
                
                int ans = dp[i][k]+ dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                
                mini = min(mini,ans);
                
            }
            
            dp[i][j] = mini;
    
        }
    }
    
    return dp[1][n-1];
    

}





int main(){

    int n ; cin >> n;

    int *arr = new int[n];

    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr , n) << endl;
    cout << matrixChainMultiplicationTabulation(arr , n) << endl;

}