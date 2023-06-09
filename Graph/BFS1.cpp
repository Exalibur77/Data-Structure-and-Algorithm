#include <iostream>
#include<vector>
#include<queue>

using namespace std;

// T.C - O(N) + O(M)
// S.C - O(N)

void solve(int startingNode , vector <int> &visited , vector <int> &bfs , vector <int> adj[]){

    visited[startingNode] = 1;

    queue <int> q;
    q.push(startingNode);

    while(!q.empty()){

        int node = q.front();
        q.pop();

        bfs.push_back(node);

        // now add all the not visited neighbours of the given node

        for(auto &i : adj[node]){

            // i neighbour is not visited make it visited
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
            }


        }

    }

}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{

    int n = vertex;

    // First form an adjacency list

    vector <int> adj[n];

    for(auto &p : edges){

        int u = p.first;
        int v = p.second;

        // since a undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

    }


    // Now go ahead for a BFS traversal

    vector <int> bfs;
    vector <int> visited(n,0);

   
    // Doing for a fully connected graph , with starting node as 0
    
    solve(0,visited , bfs , adj);

    return bfs;
    
}

int main(){

    int n;
    cin >> n;

    int m;
    cin >> m;

    vector <pair<int,int>> vp;

    for(int i=0 ; i<m ; i++){

        int u,v;

        cin >> u >> v;

        vp.push_back({u,v});

    }

    auto ans = BFS(n , vp);

    for(auto &val : ans){
        cout << val << " ";
    }

    return 0;

}