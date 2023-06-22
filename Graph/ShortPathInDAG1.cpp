//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {

  private:
    void topoSort(int start , vector <int> &visited , vector <pair<int,int>> adj[] , stack <int> &stk){
        
        // mark as visited
        visited[start] = 1;
         
        
        for(auto &it : adj[start]){
            
            int v = it.first;
            
            if(!visited[v]){
                topoSort(v , visited , adj , stk);
            }
            
        }
        
        // At last add the start value in stk
        stk.push(start);
        
    }
    
    
    
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
        
        stack <int> stk;
        vector <int> visited(N,0);
        // Fina a toposort stack 
        
        for(int i=0 ; i<N ; i++){
            
            if(!visited[i]){
                topoSort(i , visited , adj , stk);
            }
            
        }
        
        // do the distance thing
        vector <int> distance(N,INT_MAX);
        
        
        // Pop the stack untill we are unable to reach our source because above nodes have come before our source , so they are impossible to reach
        
        while(true){
            
            if(stk.top() == 0) break;
            
            stk.pop();
            
        }
        
        // mark distance of source as 
        distance[0] = 0;
        
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();

            for (auto &it: adj[node]) {
              int v = it.first;
              int wt = it.second;
    
              if (distance[node] + wt < distance[v]) {
                distance[v] = wt + distance[node];
              }
            }
        }
        
        
        
        // If any node is unreachable
        for(int i=0 ; i<N ; i++){
            
            if(distance[i] == INT_MAX) distance[i] = -1;
            
        }
        
        
        return distance;
        
    }
};


//{ Driver Code Starts.
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

// } Driver Code Ends