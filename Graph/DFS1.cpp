#include<iostream>
#include<vector>
using namespace std;

// DFS for a fully connected graph

void dfs(int V , vector<int> adj[] , vector<int> &ans , int startingNode , vector <int> &visited){
    
        ans.push_back(startingNode);
        visited[startingNode] = 1;
    
        for(auto &i : adj[startingNode]){
            
            if(!visited[i])
                dfs(V , adj , ans , i , visited);
            
            
        }
        
}
  
  
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    
    vector <int> visited(V,0);
    vector <int> ans;
    
    dfs(V , adj , ans , 0 , visited);
    
    return ans;
    
}

int main(){

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector <pair<int,int>> edges;

    for(int i=0 ; i<m ; i++){

        int u,v;

        cin >> u >> v;

        edges.push_back({u,v});

    }

    // First form an adjacency list

    vector <int> adj[n];

    for(auto &p : edges){

        int u = p.first;
        int v = p.second;

        // since a undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

    }


    auto ans = dfsOfGraph(n , adj);

    for(auto &val : ans){
        cout << val << endl;
    }


}