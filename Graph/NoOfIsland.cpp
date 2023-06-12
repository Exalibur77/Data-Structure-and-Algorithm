//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    
    void dfs(int row , int col , int n , int m ,  vector < vector<int>> &visited , vector<vector<char>>& grid){
        
        // First Step :  Mark the current i,j as visited
        
        visited[row][col] = 1;
        
        for(int dx = -1 ; dx <=  1 ; dx++){
                
            for(int dy = -1 ; dy <=  1; dy++){
                
                int nrow = row + dx;
                int ncol = col + dy;
                
                // (nrow , ncol) is the neighbour of row , col , now if it is a land and not visited
                
                if(nrow < n and nrow >=0 and ncol < m and ncol >=0 and grid[nrow][ncol] == '1' and visited[nrow][ncol] == 0){
                    
                    // mark this neighbour as visited
                    // visited[nrow][ncol] = 1;
                    
                    dfs(nrow , ncol , n , m , visited , grid);
                    
                }
                
                
                
                
            }
            
        }
        
        
        
        
    }
    
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        vector < vector<int>> visited(n , vector<int>(m,0));
        
        for(int i=0 ; i<n ; i++){
            
            for(int j=0 ; j<m ; j++){
                
                // If this land (i,j) is not visited
                if(grid[i][j] == '1' and !visited[i][j]){
                    
                    dfs(i,j,n,m,visited,grid);
                    ans++;
                    
                }
                
                // This would count my No of connecetd lands in a 2D array
                
                
                
            }
            
            
        }
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends