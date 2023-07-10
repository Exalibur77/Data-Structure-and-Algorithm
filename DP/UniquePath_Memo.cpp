#include <iostream>
#include <vector> 

using namespace std;

int f(int i , int j , vector < vector<int> > &dp){

	// base case
	if(i == 0 and j == 0){
		return 1;
	}

	if(i<0 or j<0) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int left = f(i,j-1,dp);

	int up = f(i-1 , j,dp);

	return dp[i][j] = left+up;
}



int uniquePaths(int n, int m) {
	
	vector < vector<int> > dp(n , vector<int>(m,-1));

	return f(n-1 , m-1 , dp);

}

int main(){

    int n = 5;
    int m = 3;

    cout << uniquePaths(5,3) << endl;

    return 0;
}