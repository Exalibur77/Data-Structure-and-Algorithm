#include<iostream>
#include<vector>
using namespace std;

int fib1(int n , vector <int> &dp){

    // base case
    if(n <= 1) return n;

    // check wether this suproblem is already being solved or not

    if(dp[n] != -1)
        return dp[n];


    return dp[n] = fib1(n-1 , dp) + fib1(n-2 , dp);

}

int fib2(int n , vector <int> &dp){

    // base case
    if(n <= 1) return n;

    // check wether this suproblem is already being solved or not

    if(dp[n] != -1)
        return dp[n];

    dp[n] = fib2(n-1 , dp) + fib2(n-2 , dp);
    
    return dp[n];

}

int fibTabulation(int n){

    vector <int> dp(n+1 , -1);

    // Initialising the base case first and then move to the original problem
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2 ; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n]; 

}


int main(){

    int n;
    cin>> n;

    vector <int> dp(n+1 , -1);

    cout << fib1(n , dp) << endl;

    dp = vector <int>  (n+1 , -1);

    cout << fib2(n, dp) << endl;

    // Using Tabulation
    cout << fibTabulation(n) << endl;


}