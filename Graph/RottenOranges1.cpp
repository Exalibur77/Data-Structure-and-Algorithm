//{ Driver Code Starts
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{

public:

    int row;
    int col;
    int time;

    Node(int row , int col , int time){

        this->row = row;
        this->col = col;
        this->time = time;
    }

};


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector <vector<int>> visited(n , vector<int>(m,0));
        
        queue < Node* > q;
        
        int freshCnt = 0;
        
        for(int i=0 ; i<n ; i++){
            
            for(int j=0 ; j<m ; j++){
                
                // rotten oraneg
                if(grid[i][j] == 2){
                    
                    Node * temp = new Node(i,j,0);
                    q.push(temp);
                    // and also mark them already visited
                    visited[i][j] = 2;
                    
                }    
                
                else if(grid[i][j] == 1){
                    freshCnt++;
                }
                
            }
            
            
        }
        
        int dx[] = { -1 , 1 , 0 , 0 };
        int dy[] = { 0 , 0 , -1 , 1 };
        
        int ans = 0;
        
        // Now go for a dfs traaversal
        
        int cnt =0;
        
        while(!q.empty()){
            
            Node * top = q.front();

            int row = top->row;
            int col = top->col;
            int t = top->time;
            
            q.pop();
            
            ans = max(ans , t);
            
            // Now go and find the neighbours of this current rotten orange and that are not previously rot and mark them as rot and increase a time cnt by 1
            
            for(int i=0 ; i<4 ; i++){
                
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                
                
                
                // If this is a valid neighbour which is fresh and not previously rotten
                if(newRow >=0 and newRow < n and newCol >=0 and newCol < m and visited[newRow][newCol] != 2 and grid[newRow][newCol] == 1){
                    
                    // mark it as rotten
                    visited[newRow][newCol] = 2;
                    
                    Node * newNode = new Node(newRow , newCol , t+1);
                    q.push(newNode);
                    cnt++;
                    
                }
                
                
            }
            
            
            
            
        }
        
        
        if(freshCnt != cnt) return -1;
       
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends