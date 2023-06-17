//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include<vector>
#include<set>
using namespace std;



// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};
    
    void dfs(int row , int col , vector < vector<int>> &visited , vector<vector<int>>& grid , int n , int m , int row0 , int col0 , vector < pair<int,int>> &pattern){
        
        
        visited[row][col] = 1;
        
        // forming pattern of each island with a reference of the starting island node(row0 , col0)
        pattern.push_back({row-row0 , col-col0});
        
        
        // now call dfs for all its neighbour
        for(int i=0 ; i<4 ; i++){
            
            int newRow = row+dx[i];
            int newCol = col+dy[i];
            
            if(newRow >=0 and newRow < n and newCol >=0 and newCol < m and visited[newRow][newCol] == 0 and grid[newRow][newCol] == 1){
                
                dfs(newRow , newCol , visited , grid , n , m , row0 , col0 , pattern);
                
            }
            
            
            
        }
        
        
    }
  
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector < vector<int>> visited(n , vector <int>(m,0));
        
        set < vector <pair<int,int> > >st; 
        
        for(int i=0 ; i< n ; i++){
            
            for(int j=0 ; j<m ; j++){
                
                if(grid[i][j] == 1 and visited[i][j] == 0){
                    
                    // Storing pattern of all the island groups
                    vector < pair<int,int>> pattern;
                    
                    dfs(i , j , visited , grid , n , m , i , j , pattern);
                    
                    st.insert(pattern);
                }
                
                
            }
            
            
        }
        
        
        return st.size();
        
    
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends