//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// T.C - O(N*M) + O(N*M)[dfs]
// S.C - O(N*M)


// } Driver Code Ends
class Solution {
private:
    
    void bfs(int row , int col , int n , int m ,  vector < vector<int>> &visited , vector<vector<char>>& grid){
        
        // First Step :  Mark the current i,j as visited
        
        visited[row][col] = 1;
        
        queue < pair<int,int> > q;
        q.push({row,col});
        
        
        while(!q.empty()){
            
            auto node = q.front();
            
            row = node.first;
            col = node.second;
            
            q.pop();
            
            // Now traverse for all its neighbour and add them to queue of they are not visited
            
            for(int dx = -1 ; dx <=  1 ; dx++){
                
                for(int dy = -1 ; dy <=  1; dy++){
                    
                    int nrow = row + dx;
                    int ncol = col + dy;
                    
                    // (nrow , ncol) is the neighbour of row , col , now if it is a land and not visited
                    
                    if(nrow < n and nrow >=0 and ncol < m and ncol >=0 and grid[nrow][ncol] == '1' and visited[nrow][ncol] == 0){
                        
                        // mark this neighbour as visited
                        visited[nrow][ncol] = 1;
                        
                        q.push({nrow,ncol});
                        
                    }
                    
                    
                    
                    
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
                    
                    bfs(i,j,n,m,visited,grid);
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