#include <iostream>
#include <vector> 

using namespace std;

int uniquePaths(int n, int m) {
	
	vector < vector<int> > dp(n , vector<int>(m,-1));

	dp[0][0] = 1;

	for(int i=0 ; i<n ; i++){

		for(int j=0 ; j<m ; j++){

			if(i==0 and j==0) continue;

			int left = 0;
			int up = 0;

			if(j-1 >= 0){
				left = dp[i][j-1];
			}

			if(i-1 >= 0){
				up = dp[i-1][j];
			}

			dp[i][j] = left+up;
		}

	}

	return dp[n-1][m-1];


}

int main(){

    int n = 5;
    int m = 3;

    cout << uniquePaths(5,3) << endl;

    return 0;
}