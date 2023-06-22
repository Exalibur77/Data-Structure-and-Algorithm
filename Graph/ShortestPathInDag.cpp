#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        
        vector <pair<int,int>> adj[N];
        
        // First step is to create adjacency list for the given fraph
        
        for(int i= 0 ; i<M ; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            
        }
        
        vector <int> distance(N,INT_MAX);
        
        queue <pair<int,int>> q;
        q.push({0,0});
        
        
        // Now go for a bfs 
        while(!q.empty()){
            
            int node = q.front().first;
            int d = q.front().second;
                
            q.pop();
            
            distance[node] = min(distance[node] , d);
            
            for(auto &it : adj[node]){
                
                int neigh = it.first;
                int neighDist = it.second;
                
                q.push({neigh , d+neighDist});
                
            }
            
        }
        
        for(int i=0 ; i<N ; i++){
            if(distance[i] == INT_MAX) distance[i] = -1; //. this node is not reachable
        }
        
        return distance;
        
        
    }
};

/{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver