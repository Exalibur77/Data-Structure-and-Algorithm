//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector <int> distance(V,1e8);
        
        distance[S] = 0;
        
        // N-1 iteration over the edges and relax each edge
        
        for(int i=0 ; i<V-1 ; i++){
            
            for(auto &it : edges){
                
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                // try relaxing it 
                
                // u node is firstly reachable and new way of reaching v is smaller than previous way
                if(distance[u] != 1e8 and distance[u] + wt < distance[v]){
                    
                    distance[v] = distance[u] + wt;
                    
                }
            }
        }
        
        
        // Now to check for negative cycle , if on nth iteration , any distance tries to reduce more
        
        for(auto &it : edges){
            
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // Distance to reach v further got reduced , means there would definately a negative cycle in the graph
            if(distance[u] != 1e8 and distance[u] + wt < distance[v]){
                    
                return {-1};
                    
            }
        
         
        }
        
        return distance;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends