//{ Driver Code Starts
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// } Driver Code Ends

class Node{
   
   public:
   
   int row;
   int col;
   int distance;
    
    Node(int row , int col , int distance){
        
        this->row = row;
        this->col = col;
        this->distance = distance;
        
    }
    
};


class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    
	    // WE approached it as a multisource BFS problem , marking all distance for the neighbouring 0 and so on by increasing distance by1 at every step
	    
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    
	    vector < vector <int>> visited(n , vector <int> (m,0));
	    
	    vector < vector <int>> ans(n , vector <int>(m,0));
	    
	    queue < Node*> q;
	    
	    for(int i=0 ; i<n ; i++){
	        
	        for(int j=0 ; j<m ; j++){
	            
	            // if the cell is 1 store it in queue with position and distance as 0;
	            if(grid[i][j] == 1){
	                visited[i][j] = 1;
	                Node * temp = new Node(i , j , 0);
	                q.push(temp);
	                
	            }
	           
	            
	        }
	        
	
	    }
	    
	    int dx[4] = {0 , 0 , 1 , -1};
	    int dy[4] = {-1 , 1 , 0 , 0};
	    
	    // Now start the BFS traversal
	    
	    while(!q.empty()){
	        
	        auto front = q.front();
	        
	        int row = front->row;
	        int col = front->col;
	        int distance = front->distance;
	        
	        q.pop();
	        
	        // mark the current distance in ans
	        ans[row][col]= distance;
	        
	        
	        for(int i=0 ; i<4 ; i++){
	            
	            int nr = row+dx[i];
	            int nc = col + dy[i];
	            
	            
	            if(nr >=0 and nr < n and nc >=0 and nc < m and visited[nr][nc] == 0 and grid[nr][nc] == 0){
	                
	                Node * neighbour = new Node(nr , nc , distance+1);
	                visited[nr][nc] =1;
	                q.push(neighbour);
	                
	            }
	            
	            
	        }
	        
	        
	        
	    }
	    
	    return ans;
	    
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends