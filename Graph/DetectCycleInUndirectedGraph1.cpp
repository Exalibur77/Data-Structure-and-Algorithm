//{ Driver Code Starts
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// Using DFS

// T.C - O(N + 2E)
// S.C - O(N)

class Solution {
    
private:

    bool isConnected(int startNode , int parent , vector <int>& visited , vector<int> adj[]){
        
        
        visited[startNode] = 1;
        
        for(auto &neighbourNode : adj[startNode]){
            
            
            if(!visited[neighbourNode]){
                
                bool success = isConnected(neighbourNode , startNode , visited , adj);
                
                if(success) return true;
                
            }
            
            // already visited neighbour but not a parent means we founnd the cycle so return true
            else if(neighbourNode != parent){
                return true;
            }
            
            
        }
        
        return false;
        
        
    }

    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector <int> visited(V,0);
        
        for(int i=0 ; i<V ; i++){
            
            if(!visited[i]){
                
                bool isCycleInComponent = isConnected(i , -1 , visited , adj);
                
                if(isCycleInComponent) return true;
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