//{ Driver Code Starts
// Initial Template for C++
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(destination.first == source.first and destination.second == source.second) return 0;
            
        // Can be done using the priority queue here I have prefered queue because already all the distance would be fashion of 1111, 222, 333 so there is no need to use a priority_queue
        queue < pair<int, pair<int,int>>  > pq;
        
        vector < vector <int> > distance(n , vector<int>(m , INT_MAX));
        
        pq.push({0, source});
        
        distance[source.first][source.second] = 0;
        
        int dx[] = {0 , 1 , 0 , -1};
        int dy[] = {1 , 0 , -1 , 0};
        
        
        while(!pq.empty()){
            
            int dis = pq.front().first;
            auto src = pq.front().second;
            
            int x = src.first;
            int y = src.second;
            
            pq.pop();
            
            // Now start the traveral in its neighbour
            
            for(int i=0 ; i<4 ; i++){
                
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                // First of all ist should be a valid neighbour
                
                if(newx >=0 and newx < n and newy >=0 and newy < m and grid[newx][newy] == 1){
                    
                    // Check if new way to reach this destination cell {newx , newy} is smaller
                    
                    if(1 + dis < distance[newx][newy]){
                        
                        distance[newx][newy] = 1+dis;
                        
                        if(newx == destination.first and newy == destination.second) return 1+dis;
                        
                        pq.push({ 1+ dis , {newx , newy}});
                        
                        
                    }
                    
                    
                }
                
                
                
            }
            
            
            
            
            
            
            
        }
        
        return -1 ;
        
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends