//{ Driver Code Starts
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// Using BFS

// T.C - O(N + 2E)
// S.C - O(N)

// } Driver Code Ends
class Solution {
  
  private:
  
    bool detect(int startNode ,  vector<int> adj[] , vector<int> &visited){
        
        visited[startNode] = 1;
        
        // { neighbour , parent}
        queue < pair<int,int>> q;
        
        q.push({startNode , -1});
        
        
        while(!q.empty()){
            
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            
            // Now move into its ajaacent Neighbour
            
            for(auto &adjacentNode : adj[node]){
                
                // if this neighbour is not previously visted 
                if(!visited[adjacentNode]){
                    
                    visited[adjacentNode] =1;
                    
                    q.push({adjacentNode , node});
                    
                }
                
                // neighbour of this current node is already visited and this neighbour is not its parent , then someone has alreay visited it , ie cycle is formed
                else if( adjacentNode != parent){
                    
                    return true;
                    
                }
                
                
            }
            
            
            
            
        }
        
        return false;
        
    }
  
  
  public:
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector <int> visited(V,0);
        
        // Now there is a possbility of disconnected compents in graph , so we have to check for cycle in each such discconnected component
        
        for(int i=0 ; i<V ; i++){
            
            // if it is not visited start with it and check for cycle
            if(!visited[i]){
                
                bool isCyclePresentInComponent = detect(i , adj , visited);
                
                if(isCyclePresentInComponent) return true;
                       
            }
            
            
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends