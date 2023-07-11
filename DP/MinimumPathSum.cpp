#include <iostream>
#include <vector> 

using namespace std;

int minSumPathUtil(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
  if(i==0 && j == 0)
    return matrix[0][0];
  if(i<0 || j<0)
    return 1e9;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = matrix[i][j]+minSumPathUtil(i-1,j,matrix,dp);
  int left = matrix[i][j]+minSumPathUtil(i,j-1,matrix,dp);
  
  return dp[i][j] = min(up,left);
  
}

int minSumPath(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return minSumPathUtil(n-1,m-1,matrix,dp);
    
}

int minSumPathTab(int n, int m, vector<vector<int> > &matrix){

    vector<vector<int> > dp(n,vector<int>(m,0));

    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){

            if(i==0 && j==0) dp[i][j] = matrix[i][j];

            else{
                
                int up = INT_MAX;
                if(i>0) up = matrix[i][j] + dp[i-1][j];
                
                
                int left = INT_MAX;
                if(j>0) left = matrix[i][j] + dp[i][j-1];
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
    
}

int minSumPathSpace(int n, int m, vector<vector<int> > &matrix){

    vector <int> prev(m,-1);

    for(int i=0; i<n ; i++){

        vector <int> curr(m,-1);

        for(int j=0; j<m; j++){

            if(i==0 && j==0) curr[j] = matrix[i][j];

            else{
                
                int up = INT_MAX;
                if(i>0) up = matrix[i][j] + prev[j];
                
                
                int left = INT_MAX;
                if(j>0) left = matrix[i][j] + curr[j-1];
                
                curr[j] = min(up,left);
            }
        }

        prev = curr;
    }
    
    return prev[m-1];
    
}

int main() {

  vector<vector<int> > matrix{{5,9,6},
                            {11,5,2}};
                            
  int n = matrix.size();
  int m = matrix[0].size();
  
  cout<<minSumPath(n,m,matrix) << endl ;
  cout<<minSumPathTab(n,m,matrix) << endl;
  cout<<minSumPathSpace(n,m,matrix) << endl;
}