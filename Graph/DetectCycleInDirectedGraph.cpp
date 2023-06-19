//{ Driver Code Starts
#include <iostream>
#include<vector>
using namespace std;

//  Using a Path Visited Array

class Solution {
  public:
  
    bool dfs(int start , vector <int> &visited,  vector <int> &pathVisited , vector<int> adj[]){
        
        
        visited[start] = 1;
        pathVisited[start] = 1;
        
        for(auto &neighbour : adj[start]){
            
            // not visited neighbour
            if(visited[neighbour] == 0){
                
                bool success = dfs(neighbour , visited , pathVisited, adj);
                
                if(success == true) return true;
                
            }
            
            // previously visited and also in the same path as current
            
            else if(pathVisited[neighbour] == 1){
                return true;
            } 
            
            
        }
        
        // after coming back remove all of the nodes from the current path
        pathVisited[start] = 0;
        
        
        return false;
        
        
    }
  
 
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector <int> visited(V,0);
        vector <int> pathVisited(V,0);
        
        for(int i=0 ; i<V ; i++){
            
            if(visited[i] == 0){
                if(dfs(i , visited , pathVisited , adj) == 1){
                    return true;
                    
                } 
            }       
            
        }
    
        
        return false;
        
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends