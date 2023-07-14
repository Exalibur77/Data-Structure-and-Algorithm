#include <iostream>
#include <vector>

using namespace std;

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, 
vector<vector<int> > &dp){
    
    // Base Conditions
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
    
}

int getMaxPathSumTab(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    // Now start the bottom up traversal
    for(int i=1 ; i<n ; i++){

        for(int j=0 ; j<m ; j++){

            int leftD = INT_MIN;
            int up = INT_MIN;
            int rightD = INT_MIN;

            if(i-1 >=0 and j-1 >= 0)
                leftD = dp[i-1][j-1];

            if(i-1 >=0 and j<m)
                up =  dp[i-1][j];

            if(i-1 >=0 and j+1 <m)    
                rightD = dp[i-1][j+1];

            dp[i][j] = matrix[i][j] + max({leftD , up , rightD});

        }



    }

    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
}


int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        int ans = getMaxUtil(n-1,j,m,matrix,dp);
        maxi = max(maxi,ans);
    }
    
    return maxi;
}

int main() {

  vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
  cout<<getMaxPathSum(matrix);
}