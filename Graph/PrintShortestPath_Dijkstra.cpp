//{ Driver Code Starts
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // First create an adjacency list of pair
        vector < pair<int,int> > adj[n+1];
        
        for(int i=0 ; i<m ; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        
        // Initialize the parent with itself only
        vector <int> parent(n+1);
        
        for(int i= 1; i<n ; i++){
            
            parent[i] = i;
            
        }
        
        vector <int> distance(n+1 , INT_MAX);
        
        priority_queue < pair<int,int> , vector <pair<int,int>> , greater<pair<int,int>> > pq;
        
        pq.push({0 , 1}); // source is 1
        
        distance[1] = 0;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int dis = pq.top().first;
            
            pq.pop();
            
            // Now move in all its neighbour
            
            for(auto &it : adj[node]){
                
                int neigh = it.first;
                int wt = it.second;
                
                // new distance to reach neigh is smaller than previously stored one
                if(dis + wt < distance[neigh]){
                    
                    distance[neigh] = dis + wt;
                    pq.push({dis + wt , neigh});
                    
                    // Also mark the change in parent vector as well , which stores the parent such smaller distance is achieved
                    parent[neigh] = node;
                }
                
                
                
            }
            
            
            
        }
        
        // If we are unable to reach n ( destination from our source we return -1 )
        if(distance[n] == INT_MAX) return {-1};
        
        vector <int> ans;
        
        // Noe just have to store the path using the parent vector
        
        // Destination is N
        
        int node = n;
        
        while(parent[node] != node){
            
            ans.push_back(node);
            
            node = parent[node]; //  moving backwards to its parent
        }
        // when it would reach sourcce node == 1 , it would break
        
        ans.push_back(1); // push the start node or source
        
        reverse(ans.begin() , ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
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

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends